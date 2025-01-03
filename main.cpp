/*
______________________________________________________
|                           |                         |
|       Group member        |        Matric No.       |
|___________________________|_________________________|
|                           |                         |
|   TANG JIN SHEN           |         23301943        | 
|                           |                         |
|                           |                         |
|                           |                         |
|                           |                         |
|                           |                         |
|                           |                         |
|___________________________|_________________________|

Title: Airline reservation system
*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void login();
void registeration();
void forgot();

int main()
{
   int welcome;
   cout << "\t\t\t_______________________________________________________________________\n\n\n";
   cout << "\t\t\t                   Welcome to Group 35 Airline Reservation System                 \n\n\n ";
   cout << "\t\t\t______________________________ Main menu_______________________________\n\n";
   cout << "                                                                                       \n\n";
   cout << "| Press 1 ---- Login reservation ID              |" << endl;
   cout << "| Press 2 ---- Register a reservation            |" << endl;
   cout << "| Press 3 ---- Forget password                   |" << endl;
   cout << "| Press 4 ---- Exit                              |" << endl;
   cout << "\nEnter your choice > ";
   cin >> welcome;
   cout << endl;

   switch (welcome)
   {
        case 1:
            login();
            break;
        
        case 2:
            registeration();
            break;
        
        case 3:
            forgot();
            break;
        
        case 4:
            cout << "\t\t\t Existing the program..... Thanks for using!! \n\n";
            break;
        
        default:
            system("cls");
            cout << "\t\t\t Please select option 1-4 from the main menu page above";
            main();
   }
}

void login()
{
    int count;
    string user_ID1, password1, Id1, password2;
    system ("cls");
    cout << "\t\t\t Please enter Username and Password" << endl;
    cout << "\t\t\t Username > ";
    cin >> user_ID1;
    cout << "\t\t\t Password > ";
    cin >> password1;

    ifstream input("records.txt");

    while (input >> Id1 >> password2)
    {
        if(Id1 == user_ID1 && password2 == password1 )
        {
            count =1;
            system ("cls");
        }
    }
    input.close();

    if(count ==1)
    {
                        cout << " ________________________________________" << endl;
                        cout << "|                                        |" << endl;
                        cout << "|            Login Successful!           |" << endl;
                        cout << "|________________________________________|" << endl;
    
    main ();
    }

    else 
    {
                        cout << " ________________________________________" << endl;
                        cout << "|                                        |" << endl;
                        cout << "|     Incorrect Username OR Password     |" << endl;
                        cout << "|________________________________________|" << endl;
                        cout << "" << endl;
    
    main();
    }
}

void registeration()
{

    string user_ID2, password3, ID2, password4;
    system ("cls");
    cout << "\t\t\tEnter your username > ";
    cin >> user_ID2;
    cout << "\t\t\tEnter your password > ";
    cin >> password3;
    
    ofstream f1("records.txt", ios::app);
    f1<<user_ID2 << password3 << endl;
    system ("cls");
                    cout << " _______________________________________________" << endl;
                    cout << "|                                               |" << endl;
                    cout << "|    Reservation ID Registered Successfully!    |" << endl;
                    cout << "|_______________________________________________|" << endl;
    main ();
}

void forgot()
{
    int option;
    system ("cls");
    cout << "Press 1 ---- Search Username";
    cout << "Press 2 ---- Back to main menu";
    cout << "Enter your choice";
    cin >> option;

    switch(option)
    {
        case 1:
        {
            int count=0;
            string user_ID3, ID3, password5;
            cout << "\n\t\t\tEnter the username which you remembered :";
            cin >> user_ID3;

            ifstream f2("records.txt");
            while (f2>>ID3>>password5)
            {
                if(ID3==user_ID3)
                {
                    count =1;
                }
            }
            f2.close();
            if (count ==1)
            {
                cout <<"\n\n Your account had been found \n";
                cout <<"\n\n Your password is : " << password5;
                main();
            }
            else
            {
                cout << "\n\t Sorry, invalid account username\n";
                main();
            }
            break;
        }

        case 2:
        {
            main();
        }

        default:
            cout << "\t\t\t Please select option 1 or 2 from the page above " << endl;
            forgot();
    }
}