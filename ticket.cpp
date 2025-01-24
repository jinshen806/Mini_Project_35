/*Programmer name: TANG JIN SHEN
  Matric number : 23301943
  Function of this cpp file - display the ticket details of the user who has made the reservation
*/


#include "ticket.hpp"
#include <iostream>
#include <fstream>
using namespace std;

/*this code is to display the ticket details*/
void ticket(const string& username)
{
    ifstream infile("reservations.txt");
    if (!infile.is_open()) 
    {
        cout << "\t\t\t\t\t\t\t\tError: Unable to open reservation file." << endl;
        return;
    }

//this code is to get the correct position of the destination and time of flight at the reservation.txt file so that we can display it in ticket details
    string line, reservedUser, destination, time;
    while (getline(infile, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1+1);
        size_t pos3 = line.find(',', pos2+1);
        reservedUser = line.substr(0, pos1);
        destination = line.substr(pos1 + 1, pos2 - pos1 -1);
        time = line.substr(pos2 + 1, pos3 - pos2 -1);

        if (reservedUser == username) 
        {
        cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
        cout << "\t\t\t\t\t|                                                                  |" << endl;
        cout << "\t\t\t\t\t|                          Ticket details                          |" << endl;
        cout << "\t\t\t\t\t|__________________________________________________________________|" << endl;
        cout << "\t\t\t\t\t|                                                                  |" << endl;
        cout << "\t\t\t\t\t\t\t\t"                  << destination<< "\t\t\t\t\t"             <<endl;
        cout << "\t\t\t\t\t\t\t\t\t"                  << time<<        "\t\t\t\t\t"             <<endl;
        cout << "\t\t\t\t\t|               Have a nice flights, See you soon!!!               |" << endl;
        cout << "\t\t\t\t\t|__________________________________________________________________|" << endl;
            return;
        }
    }
        cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
        cout << "\t\t\t\t\t!                                                                  !" << endl;
        cout << "\t\t\t\t\t!                       No reservation found                       !" << endl;
        cout << "\t\t\t\t\t!                      Please try again later                      !" << endl;
        cout << "\t\t\t\t\t!__________________________________________________________________!" << endl;
        cout << "\n\n" << endl;
}
