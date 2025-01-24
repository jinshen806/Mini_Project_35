/* Programmer name: TANG JIN SHEN
   MATRIC NO. : 23301943
   Function for this .cpp file - this .cpp file is to cancel all the reservation that the login username has made.
*/
#include "cancelreservation.hpp"
#include <iostream>
#include <fstream>
using namespace std;

/*this code is to cancel the reservation that the login username has made
the reservation detail will be stored in the file reservations.txt
if the reservation is found, the reservation cancel successfully message will be displayed
if the reservation is not found, the no reservation found message will be displayed
this function will be used in main_menu.cpp*/
void cancelReservation(const string& username) 
{
    ifstream infile("reservations.txt");
    ofstream tempFile("temp.txt");

    if (!infile.is_open() || !tempFile.is_open()) 
    {
        cout << "\t\t\t\t\t\t\t\tError: Unable to open reservation file.\n";
        return;
    }

//this code is to get the correct position of the username at the reservation.txt file so that we can cancel the reservation
    string line, reservedUser;
    bool found = false;
    while (getline(infile, line)) 
    {
        size_t pos = line.find(',');
        reservedUser = line.substr(0, pos);

        if (reservedUser == username)
        {
            found = true;
        } 
        else 
        {
            tempFile << line << endl;
        }
    }

    infile.close();
    tempFile.close();

    remove("reservations.txt");
    rename("temp.txt", "reservations.txt");

    if (found) 
    {
        cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
        cout << "\t\t\t\t\t|                                                                  |" << endl;
        cout << "\t\t\t\t\t|                     Reservation cancel successfully              |" << endl;
        cout << "\t\t\t\t\t|                Thanks again for choosing our airline!!           |" << endl;
        cout << "\t\t\t\t\t|__________________________________________________________________|" << endl;
        cout <<"\n\n" << endl;
    } 

    else 
    {
        cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
        cout << "\t\t\t\t\t!                                                                  !" << endl;
        cout << "\t\t\t\t\t!                       No reservation found                       !" << endl;
        cout << "\t\t\t\t\t!                      Please try again later                      !" << endl;
        cout << "\t\t\t\t\t!__________________________________________________________________!" << endl;
        cout << "\n\n" << endl;
    }
}
