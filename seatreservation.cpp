//Programmer name: GARETT KHOO BOO ZHENG 
//Matric number: 23301528 
//FUnction of this cpp file: This file is to display the available seats and to book a seat for the user

#include "seatReservation.hpp"

void seatReservation() {
    FlightReservationSystem system;
    int choice;

    do {
        cout << "\n" << endl;
        cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
        cout << "\t\t\t\t\t!                                                                   !" << endl;
        cout << "\t\t\t\t\t!                     Flight Reservation System                     !\n";
        cout << "\t\t\t\t\t!                     1. Display available seats                    !\n";
        cout << "\t\t\t\t\t!                     2. Book a seat                                !\n";
        cout << "\t\t\t\t\t!                     3. Exit                                       !\n";
        cout << "\t\t\t\t\t!___________________________________________________________________!\n";
        cout << "\n" << endl;
        cout << "\t\t\t\t\t                      Enter your choice:";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
                system.displaySeats();
                break;
            case 2:
                system.bookSeat();
                break;
            case 3:
                cout << "\n" << endl;
                cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
                cout << "\t\t\t\t\t|                                                                  |" << endl;
                cout << "\t\t\t\t\t|                     Reservation successfull!!!!                  |" << endl;
                cout << "\t\t\t\t\t|                   Thanks for choosing our airline!!              |" << endl;
                cout << "\t\t\t\t\t|                      Hope have a nice journey                    |" << endl;
                cout << "\t\t\t\t\t|__________________________________________________________________|" << endl;
                cout <<"\n\n" << endl;
                break;
            default:
                cout << "\n" << endl;
                cout << "\t\t\t\t\t ___________________________________________________________________\n";
                cout << "\t\t\t\t\t!                                                                   !\n";
                cout << "\t\t\t\t\t!                         Invalid choice.                           !\n";
                cout << "\t\t\t\t\t!___________________________________________________________________!\n";
        }

    } while (choice != 3);

}
