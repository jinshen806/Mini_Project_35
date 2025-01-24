/*Programmer name: TANG JIN SHEN
  Matric number : 23301943
  Function of this cpp file - to make reservation for the user to select the destination and time of flight
    the reservation detail will be stored in the file reservations.txt according to the person who login
*/


#include "reservation.hpp"
#include <iostream>
#include <fstream>
using namespace std;

/*this code is to make reservation for the user to select the destination and time of flight
the reservation detail will be stored in the file reservations.txt but need to user need to login first before make reservation
this function will be used in main_menu.cpp*/
void makeReservation(const string& username) 
{
    ofstream outfile("reservations.txt", ios::app);
    if (!outfile.is_open())
    {
        cout << "\t\t\t\t\t\t\t\tError: Unable to open reservation file.\n";
        return;
    }

    string destinations[] = {"United States of America", "United Kingdom", "Japan", "France", "Australia", "Singapore"};
    string times[] = {"10:00a.m.", "2:00p.m.", "6:00p.m."};
            cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
            cout << "\t\t\t\t\t|                                                                  |" << endl;
            cout << "\t\t\t\t\t|                      Select your destination                     |" << endl;
            cout << "\t\t\t\t\t|__________________________________________________________________|" << endl;

    for (int i = 0; i < 6; ++i)
    {
        cout <<"\t\t\t\t\t\t\t\t" << i + 1 << ") " << destinations[i] << endl;
    }

    int choice, choice2;
    cout << "\n\t\t\t\t\t\t\t\tEnter your choice > ";
    cin >> choice;

    switch(choice)
    {
        case 1:
        cout << "\n\t\t\t\t\t\t\t\tSelect time of flight to United States of America:\n";
        cout << "\n\t\t\t\t\t\t\t\t1. 10:00a.m.  RM 1500\n";
        cout << "\n\t\t\t\t\t\t\t\t2. 2:00p.m.   RM 2000\n";
        cout << "\n\t\t\t\t\t\t\t\t3. 6:00p.m.   RM 1300\n";
        cout << "\n\t\t\t\t\t\t\t\tEnter your choice > ";
        cin >> choice2;
        if( choice2 < 1 || choice2 > 3)
        {
        cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
        cout << "\t\t\t\t\t!                                                                  !" << endl;
        cout << "\t\t\t\t\t!              Invalid choice. Please choose accordingly!!         !" << endl;
        cout << "\t\t\t\t\t!__________________________________________________________________!" << endl;
        }
        break;

        case 2:
        cout << "\n\t\t\t\t\t\t\t\tSelect time of flight to United Kingdom:\n";
        cout << "\n\t\t\t\t\t\t\t\t1. 10:00a.m.  RM 2000\n";
        cout << "\n\t\t\t\t\t\t\t\t2. 2:00p.m.   RM 3000\n";
        cout << "\n\t\t\t\t\t\t\t\t3. 6:00p.m.   RM 2500\n";
        cout << "\n\t\t\t\t\t\t\t\tEnter your choice > ";
        cin >> choice2;
        if( choice2 < 1 || choice2 > 3)
        {
        cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
        cout << "\t\t\t\t\t!                                                                  !" << endl;
        cout << "\t\t\t\t\t!              Invalid choice. Please choose accordingly!!         !" << endl;
        cout << "\t\t\t\t\t!__________________________________________________________________!" << endl;
        }
        break;

        case 3:
        cout << "\n\t\t\t\t\t\t\t\tSelect time of flight to Japan:\n";
        cout << "\n\t\t\t\t\t\t\t\t1. 10:00a.m.  RM 3000\n";
        cout << "\n\t\t\t\t\t\t\t\t2. 2:00p.m.   RM 2500\n";
        cout << "\n\t\t\t\t\t\t\t\t3. 6:00p.m.   RM 2200\n";
        cout << "\n\t\t\t\t\t\t\t\tEnter your choice > ";
        cin >> choice2;
        if( choice2 < 1 || choice2 > 3)
        {
        cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
        cout << "\t\t\t\t\t!                                                                  !" << endl;
        cout << "\t\t\t\t\t!              Invalid choice. Please choose accordingly!!         !" << endl;
        cout << "\t\t\t\t\t!__________________________________________________________________!" << endl;
        }
        break;

        case 4:
        cout << "\n\t\t\t\t\t\t\t\tSelect time of flight to France:\n";
        cout << "\n\t\t\t\t\t\t\t\t1. 10:00a.m.  RM 2450\n";
        cout << "\n\t\t\t\t\t\t\t\t2. 2:00p.m.   RM 2700\n";
        cout << "\n\t\t\t\t\t\t\t\t3. 6:00p.m.   RM 2900\n";
        cout << "\n\t\t\t\t\t\t\t\tEnter your choice > ";
        cin >> choice2;
        if( choice2 < 1 || choice2 > 3)
        {
        cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
        cout << "\t\t\t\t\t!                                                                  !" << endl;
        cout << "\t\t\t\t\t!              Invalid choice. Please choose accordingly!!         !" << endl;
        cout << "\t\t\t\t\t!__________________________________________________________________!" << endl;
        }
        break;

        case 5:
        cout << "\n\t\t\t\t\t\t\t\tSelect time of flight to Australia:\n";
        cout << "\n\t\t\t\t\t\t\t\t1. 10:00a.m.  RM 2460\n";
        cout << "\n\t\t\t\t\t\t\t\t2. 2:00p.m.   RM 3300\n";
        cout << "\n\t\t\t\t\t\t\t\t3. 6:00p.m.   RM 2500\n";
        cout << "\n\t\t\t\t\t\t\t\tEnter your choice > ";
        cin >> choice2;
        if( choice2 < 1 || choice2 > 3)
        {
        cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
        cout << "\t\t\t\t\t!                                                                  !" << endl;
        cout << "\t\t\t\t\t!              Invalid choice. Please choose accordingly!!         !" << endl;
        cout << "\t\t\t\t\t!__________________________________________________________________!" << endl;
        }
        break;

        case 6:
        cout << "\n\t\t\t\t\t\t\t\tSelect time of flight to Singapore:\n";
        cout << "\n\t\t\t\t\t\t\t\t1. 10:00a.m.  RM 900\n";
        cout << "\n\t\t\t\t\t\t\t\t2. 2:00p.m.   RM 700\n";
        cout << "\n\t\t\t\t\t\t\t\t3. 6:00p.m.   RM 500\n";
        cout << "\n\t\t\t\t\t\t\t\tEnter your choice > ";
        cin >> choice2;
        if( choice2 < 1 || choice2 > 3)
        {
        cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
        cout << "\t\t\t\t\t!                                                                  !" << endl;
        cout << "\t\t\t\t\t!              Invalid choice. Please choose accordingly!!         !" << endl;
        cout << "\t\t\t\t\t!__________________________________________________________________!" << endl;
        }
        break;

        default:
        cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
        cout << "\t\t\t\t\t!                                                                  !" << endl;
        cout << "\t\t\t\t\t!                Invalid choice. Please try again later!!          !" << endl;
        cout << "\t\t\t\t\t!__________________________________________________________________!" << endl;
        break;
    }


    outfile << username << "," << destinations[choice - 1] << "," << times[choice2 - 1] << endl;
        cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
        cout << "\t\t\t\t\t|                                                                  |" << endl;
        cout << "\t\t\t\t\t|                     Reservation successfull!!!!                  |" << endl;
        cout << "\t\t\t\t\t|                   Thanks for choosing our airline!!              |" << endl;
        cout << "\t\t\t\t\t|                      Hope have a nice journey                    |" << endl;
        cout << "\t\t\t\t\t|__________________________________________________________________|" << endl;
        cout <<"\n\n" << endl;

    outfile.close();
}