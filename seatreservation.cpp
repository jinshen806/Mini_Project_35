#include "seatReservation.hpp"

void seatReservation() {
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
