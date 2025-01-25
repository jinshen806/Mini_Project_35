#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct FlightClass {
    string className;
    vector<string> seats;  // Using string to represent "O" or "X"
    int rows;
    int columns;
};

class FlightReservationSystem {
private:
    vector<FlightClass> flightClasses;
    const string dataFile = "seats_data.txt";  // Ensure this file is in the same directory

    void loadData() {
        ifstream input(dataFile);
        if (!input.is_open()) {
            cout << "Error opening file. No previous booking data found.\n";
            return;  // No file found, no data to load
        }

        flightClasses.clear();  // Clear previous data before loading
        string line;
        while (getline(input, line)) {
            if (line.empty()) continue;

            FlightClass flightClass;
            flightClass.className = line;

            input >> flightClass.rows >> flightClass.columns;
            input.ignore(); // Ignore the newline after the rows and columns number

            // Read seat grid as a single string (O for available, X for booked)
            for (int i = 0; i < flightClass.rows; i++) {
                string seatRow;
                getline(input, seatRow);  // Read each row of seats as a string
                flightClass.seats.push_back(seatRow);
            }
            flightClasses.push_back(flightClass);
        }
        input.close();
    }

    // Save seat data to the file in "O" and "X" format
    void saveData() {
        ofstream output(dataFile);
        if (!output.is_open()) {
            cout << "Error opening file to save data.\n";
            return;
        }

        for (const auto &flightClass : flightClasses) {
            output << flightClass.className << "\n";
            output << flightClass.rows << " " << flightClass.columns << "\n";  // Save rows and columns
            for (const auto &row : flightClass.seats) {
                output << row << "\n";  // Save seat grid as a string of "O"s and "X"s
            }
        }
        output.close();
    }

    // Generate seat layout for a given class
    vector<string> generateSeats(int rows, int columns) {
        vector<string> seats;
        string row;
        for (int i = 0; i < rows; i++) {
            row = string(columns, 'O');  // Initialize each row with "O" (available seat)
            seats.push_back(row);
        }
        return seats;
    }

public:
    FlightReservationSystem() {
        loadData();  // Try loading data from the file

        if (flightClasses.empty()) {
            initializeSeats();  // Initialize seat data if no data file exists
            saveData();  // Save the newly initialized data to the file
        }
    }

    void initializeSeats() {
        flightClasses = {
            {"First Class", generateSeats(6, 8), 6, 8},
            {"Business Class", generateSeats(8, 8), 8, 8},
            {"Economy Class", generateSeats(15, 8), 15, 8}
        };
    }

    // Display the seat availability
    void displaySeats() {
        for (const auto &flightClass : flightClasses) {
            cout << "\n" << flightClass.className << " Seats:\n";

            // Print column labels (A, B, C, ...)
            cout << "   ";
            for (char col = 'A'; col < 'A' + flightClass.columns; col++) {
                cout << "  " << col << "   ";
            }
            cout << endl;

            // Print rows and seat availability (O for available, X for booked)
            for (int i = 0; i < flightClass.rows; i++) {
                cout << setw(2) << (i + 1) << " ";
                for (int j = 0; j < flightClass.columns; j++) {
                    cout << " [" << flightClass.seats[i][j] << "]  ";  // Display seat status
                }
                cout << endl;
            }
        }
    }

    // Book a seat with validation
    void bookSeat() {
        string className;
        cout << "\nEnter flight class (First Class, Business Class, Economy Class): ";
        getline(cin, className);

        FlightClass *flightClass = nullptr;
        for (auto &fc : flightClasses) {
            if (fc.className == className) {
                flightClass = &fc;
                break;
            }
        }

        if (flightClass == nullptr) {
            cout << "Invalid class name.\n";
            return;
        }

        cout << "Available seats in " << flightClass->className << ":\n";
        displaySeats();  // Show the seat layout

        string seatInput;
        cout << "\nEnter seat(s) to book (e.g., 1A, 10B, 12C): ";
        getline(cin, seatInput);

        // Split the input by commas and process each seat one by one
        size_t pos = 0;
        while ((pos = seatInput.find(',')) != string::npos) {
            string seat = seatInput.substr(0, pos);
            seatInput.erase(0, pos + 1);  // Remove the processed seat

            if (bookSingleSeat(flightClass, seat)) {
                cout << "Seat " << seat << " successfully booked in " << flightClass->className << ".\n";
            }
        }
    }

    // Book a single seat
    bool bookSingleSeat(FlightClass* flightClass, const string& seatInput) {
        if (seatInput.length() < 2 || seatInput[seatInput.length() - 1] < 'A' || seatInput[seatInput.length() - 1] >= 'A' + flightClass->columns) {
            cout << "Invalid seat input. Please enter in the format: RowColumn (e.g., 1A, 10B, 12C).\n";
            return false;
        }

        // Extract the column letter and the row number from the input
        char col = seatInput[seatInput.length() - 1]; // Last character is the column letter
        string rowStr = seatInput.substr(0, seatInput.length() - 1); // All but the last character is the row number

        int row = stoi(rowStr); // Convert the row string to an integer

        // Check if the row and column are valid
        if (row < 1 || row > flightClass->rows || col < 'A' || col >= 'A' + flightClass->columns) {
            cout << "Invalid seat " << seatInput << ". Row or column out of bounds.\n";
            return false;
        }

        // Calculate seat index in the array
        int seatIndex = (row - 1) * flightClass->columns + (col - 'A');

        // Check if the seat is already booked
        if (flightClass->seats[row - 1][col - 'A'] == 'X') {
            cout << "Seat " << seatInput << " is already booked.\n";
            return false;
        }

        // Book the seat
        flightClass->seats[row - 1][col - 'A'] = 'X';  // Mark as booked ("X")
        saveData();  // Save the updated seat status to the file

        return true;
    }
};

void seatReservation();