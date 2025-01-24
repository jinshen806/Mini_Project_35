#include "seatreservation.hpp"

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

    void displaySeats() {
        for (const auto &flightClass : flightClasses) {
            cout << "\n" << flightClass.className << " Seats:\n";

            cout << "   ";
            for (char col = 'A'; col < 'A' + flightClass.columns; col++) {
                cout << "  " << col << "   ";
            }
            cout << endl;

            for (int i = 0; i < flightClass.rows; i++) {
                cout << setw(2) << (i + 1) << " ";
                for (int j = 0; j < flightClass.columns; j++) {
                    cout << " [" << flightClass.seats[i][j] << "]  ";
                }
                cout << endl;
            }
        }
    }

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
        displaySeats();

        string seatInput;
        cout << "\nEnter seat(s) to book (e.g., 1A, 10B, 12C): ";
        getline(cin, seatInput);

        size_t pos = 0;
        while ((pos = seatInput.find(',')) != string::npos) {
            string seat = seatInput.substr(0, pos);
            seatInput.erase(0, pos + 1);

            if (bookSingleSeat(flightClass, seat)) {
                cout << "Seat " << seat << " successfully booked in " << flightClass->className << ".\n";
            }
        }
    }

    bool bookSingleSeat(FlightClass* flightClass, const string& seatInput) {
        if (seatInput.length() < 2 || seatInput[seatInput.length() - 1] < 'A' || seatInput[seatInput.length() - 1] >= 'A' + flightClass->columns) {
            cout << "Invalid seat input. Please enter in the format: RowColumn (e.g., 1A, 10B, 12C).\n";
            return false;
        }

        char col = seatInput[seatInput.length() - 1];
        string rowStr = seatInput.substr(0, seatInput.length() - 1);

        int row = stoi(rowStr);

        if (row < 1 || row > flightClass->rows || col < 'A' || col >= 'A' + flightClass->columns) {
            cout << "Invalid seat " << seatInput << ". Row or column out of bounds.\n";
            return false;
        }

        int seatIndex = (row - 1) * flightClass->columns + (col - 'A');

        if (flightClass->seats[row - 1][col - 'A'] == 'X') {
            cout << "Seat " << seatInput << " is already booked.\n";
            return false;
        }

        flightClass->seats[row - 1][col - 'A'] = 'X';
        saveData();

        return true;
    }
};

void seatreservation(const string& username) {
    FlightReservationSystem system;
    int choice;

    do {
        cout << "\nFlight Reservation System\n";
        cout << "1. Display available seats\n";
        cout << "2. Book a seat\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                system.displaySeats();
                break;
            case 2:
                system.bookSeat();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 3);

}
