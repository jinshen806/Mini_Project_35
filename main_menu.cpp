/*Programmer name: TANG JIN SHEN
  Matric number : 23301943
  Function of this cpp file - display the main menu page at the terminal for main menu selection and to call the function from other cpp file
  user need to select according to the main menu selection and the program will run according to the selection
*/

#include <iostream>
#include "main_menu.hpp"
#include "exit.hpp"
#include "invalid.hpp"
#include "reservation.hpp"
#include "ticket.hpp"
#include "cancelreservation.hpp"

using namespace std;

void mainMenu(LoginRegisterForgot &loginregisterforgot) 
{
    string loginCustomer;
    bool isLoggedIn = false;
    int choice;

    do 
    {
    cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
    cout << "\t\t\t\t\t|                                                                  |" << endl;
    cout << "\t\t\t\t\t|                            Main Menu                             |" << endl;
    cout << "\t\t\t\t\t|__________________________________________________________________|" << endl;
    cout << "\t\t\t\t\t|                                                                  |" << endl;
    cout << "\t\t\t\t\t|                  Press 1 ---- 1) Login Customer ID               |" << endl;
    cout << "\t\t\t\t\t|                  Press 2 ---- 2) Register Customer ID            |" << endl;
    cout << "\t\t\t\t\t|                  Press 3 ---- 3) Forget password                 |" << endl;
    cout << "\t\t\t\t\t|                  Press 4 ---- 4) Airline ticket reservation      |" << endl;
    cout << "\t\t\t\t\t|                  Press 5 ---- 5) Ticket bill                     |" << endl;
    cout << "\t\t\t\t\t|                  Press 6 ---- 6) Cancel reservation              |" << endl;
    cout << "\t\t\t\t\t|                  Press 7 ---- 7) Exit                            |" << endl;
    cout << "\t\t\t\t\t|__________________________________________________________________|" << endl;
    cout << "\n"<< endl;
    cout << "\t\t\t\t\t                     Enter your choice > ";
        cin >> choice;

        switch (choice) 
        {
        case 1:

            loginregisterforgot.loginCustomer();
            isLoggedIn = true; 
            break;

        case 2:

            loginregisterforgot.registerCustomer();
            break;

        case 3:

            loginregisterforgot.forgotPassword();
            break;

        case 4:

            if (isLoggedIn) 
            {
                makeReservation(loginCustomer);
            } 
            else 
            {
            cout << "\n" << endl;
            cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
            cout << "\t\t\t\t\t!                                                                  !" << endl;
            cout << "\t\t\t\t\t!            Please login first before enter this choice!!!        !" << endl;
            cout << "\t\t\t\t\t!__________________________________________________________________!" << endl;
            cout << "\n\n" << endl;
            }
            break;

        case 5:

            if (isLoggedIn) 
            {
                ticket(loginCustomer);
            }
            else 
            {
            cout << "\n" << endl;
            cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
            cout << "\t\t\t\t\t!                                                                  !" << endl;
            cout << "\t\t\t\t\t!            Please login first before enter this choice!!!        !" << endl;
            cout << "\t\t\t\t\t!__________________________________________________________________!" << endl;
            cout << "\n\n" << endl;
            }
            break;

        case 6:
            if (isLoggedIn) 
            {
                cancelReservation(loginCustomer);
            } 
            else 
            {
            cout << "\n" << endl;
            cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
            cout << "\t\t\t\t\t!                                                                  !" << endl;
            cout << "\t\t\t\t\t!            Please login first before enter this choice!!!        !" << endl;
            cout << "\t\t\t\t\t!__________________________________________________________________!" << endl;
            cout << "\n\n" << endl;
            }
            break;
        
        case 7:
            exitPage();
            break;
            
        default:
            invalidMessage();
            break;
        }
        
    } while (choice != 7);
}