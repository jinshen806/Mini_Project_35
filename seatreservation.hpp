#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct FlightClass {
    string className;
    vector<string> seats;
    int rows;
    int columns;
};

class FlightReservationSystem {
private:
    vector<FlightClass> flightClasses;
    const string dataFile = "seats_data.txt";

    void loadData() {
        ifstream input(dataFile);
        if (!input.is_open()) {
            cout << "Error opening file. No previous booking data found.\n";
            return;
        }

        flightClasses.clear();
        string line;
        while (getline(input, line)) {
            if (line.empty()) continue;

            FlightClass flightClass;
            flightClass.className = line;

            input >> flightClass.rows >> flightClass.columns;
            input.ignore();

            for (int i = 0; i < flightClass.rows; i++) {
                string seatRow;
                getline(input, seatRow);
                flightClass.seats.push_back(seatRow);
            }
            flightClasses.push_back(flightClass);
        }
        input.close();
    }

    void saveData() {
        ofstream output(dataFile);
        if (!output.is_open()) {
            cout << "Error opening file to save data.\n";
            return;
        }

        for (const auto &flightClass : flightClasses) {
            output << flightClass.className << "\n";
            output << flightClass.rows << " " << flightClass.columns << "\n";
            for (const auto &row : flightClass.seats) {
                output << row << "\n";
            }
        }
        output.close();
    }

    vector<string> generateSeats(int rows, int columns) {
        vector<string> seats;
        string row;
        for (int i = 0; i < rows; i++) {
            row = string(columns, 'O');
            seats.push_back(row);
        }
        return seats;
    }

public:
    FlightReservationSystem() {
        loadData();

        if (flightClasses.empty()) {
            initializeSeats();
            saveData();
        }
    }

    void initializeSeats() {
        flightClasses = {
            {"First Class", generateSeats(6, 8), 6, 8},
            {"Business Class", generateSeats(8, 8), 8, 8},
            {"Economy Class", generateSeats(15, 8), 15, 8}
        };
    }

    void displaySeats(FlightClass* flightClass = nullptr) {
        if (flightClass) {
            // Display seats for a specific class
            cout << "\n\t\t\t\t\t                      " << flightClass->className << " Seats:\n";
            cout << "\t\t\t\t\t          ";
            for (char col = 'A'; col < 'A' + flightClass->columns; col++) {
                cout << "  " << col << "   ";
            }
            cout << endl;

            for (int i = 0; i < flightClass->rows; i++) {
                cout << setw(49) << (i + 1) << " ";
                for (int j = 0; j < flightClass->columns; j++) {
                    cout << " [" << flightClass->seats[i][j] << "]  ";
                }
                cout << endl;
            }
        } else {
            for (const auto &fc : flightClasses) {
                cout << "\n\t\t\t\t\t                      " << fc.className << " Seats:\n";
                cout << "\t\t\t\t\t          ";
                for (char col = 'A'; col < 'A' + fc.columns; col++) {
                    cout << "  " << col << "   ";
                }
                cout << endl;

                for (int i = 0; i < fc.rows; i++) {
                    cout << setw(49) << (i + 1) << " ";
                    for (int j = 0; j < fc.columns; j++) {
                        cout << " [" << fc.seats[i][j] << "]  ";
                    }
                    cout << endl;
                }
            }
        }
    }

    void bookSeat() {
        string className;
        cout << "\n\t\t\t\t\t  Enter flight class (First Class, Business Class, Economy Class): ";
        getline(cin, className);

        FlightClass *flightClass = nullptr;
        for (auto &fc : flightClasses) {
            if (fc.className == className) {
                flightClass = &fc;
                break;
            }
        }

        if (flightClass == nullptr) {
            cout << "\n\t\t\t\t\t                      Invalid class name.\n";
            return;
        }

        cout << "\n\t\t\t\t\t                Available seats in " << flightClass->className << ":\n";
        displaySeats(flightClass);

        string seatInput;
        cout << "\n\t\t\t\t\t          Enter seat(s) to book (e.g. 1A 10B 12C): ";
        getline(cin, seatInput);

        istringstream iss(seatInput);
        string seat;

        while (iss >> seat) {
            if (bookSingleSeat(flightClass, seat)) {
                cout << "\t\t\t\t\t            Seat " << seat << " successfully booked in " << flightClass->className << ".\n";
            }
        }
    }

    bool bookSingleSeat(FlightClass* flightClass, const string& seatInput) {
        if (seatInput.length() < 2 || seatInput[seatInput.length() - 1] < 'A' || seatInput[seatInput.length() - 1] >= 'A' + flightClass->columns) {
            cout << "\t\t\t\t\t    Invalid seat input. Please enter in the format: RowColumn (e.g. 1A, 10B, 12C).\n";
            return false;
        }

        char col = seatInput[seatInput.length() - 1];
        string rowStr = seatInput.substr(0, seatInput.length() - 1);

        int row = stoi(rowStr);

        if (row < 1 || row > flightClass->rows || col < 'A' || col >= 'A' + flightClass->columns) {
            cout << "\t\t\t\t\t           Invalid seat " << seatInput << ". Row or column out of bounds.\n";
            return false;
        }

        int seatIndex = (row - 1) * flightClass->columns + (col - 'A');

        if (flightClass->seats[row - 1][col - 'A'] == 'X') {
            cout << "\t\t\t\t\t                    Seat " << seatInput << " is already booked.\n";
            return false;
        }

        flightClass->seats[row - 1][col - 'A'] = 'X';
        saveData();

        return true;
    }
};

void seatReservation();