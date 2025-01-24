/*Programmer name: TANG JIN SHEN
  Matric number : 23301943
  Function of this cpp file - to check the customer exists in the file or not, to register the customer, to login the customer and to forgot the password
  All of the customer details will be stored and read from the file customer_data.txt
*/


#include "LoginRegisterForgot.hpp"

/*this code is to check the customer exists in the file or not
if the customer exists, the password will be stored in the password variable
if the customer does not exists, the password will be stored in the errorPassword variable
this function will return true if the customer exists and false if the customer does not exists
this function will be used in registerCustomer, loginCustomer and forgotPassword function
*/
bool LoginRegisterForgot::checkCustomerExists(const string& username, string& password) 
{
    ifstream infile(customerFile);
    string fileUsername, filePassword;

    while (getline(infile, fileUsername) && getline(infile, filePassword))
    {
        if (fileUsername == username) {
            password = filePassword;
            return true;
        }
    }
    return false;
}

/*this code is to register the customer
the customer will enter the username and password
the username and password will be stored in the file customer_data.txt
if the username already exists, the error message will be displayed
if the username does not exists, the register succesfull message will be displayed
this function will be used in main_menu.cpp*/
void LoginRegisterForgot::registerCustomer() 
{
    string username, password;

    cout <<"\n" << endl;
    cout << "\t\t\t\t\t\t\t     Enter username: ";
    cin.ignore(); 
    getline(cin, username);

    string errorPassword;
    if (checkCustomerExists(username, errorPassword)) 
    {
        cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
        cout << "\t\t\t\t\t!                                                                  !" << endl;
        cout << "\t\t\t\t\t!                    This username already exists                  !" << endl;
        cout << "\t\t\t\t\t!                      Please try again later                      !" << endl;
        cout << "\t\t\t\t\t!__________________________________________________________________!" << endl;
        cout << "\n\n" << endl;
        return;
    }

    cout << "\t\t\t\t\t\t\t     Enter password: ";
    getline(cin, password);

    ofstream outfile(customerFile, ios::app);
    if (outfile.is_open()) 
    {
        outfile << username << '\n' << password << '\n';
        cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
        cout << "\t\t\t\t\t|                                                                  |" << endl;
        cout << "\t\t\t\t\t|                      Register succesfull!!!!                     |" << endl;
        cout << "\t\t\t\t\t|                             Welcome !!!                          |" << endl;
        cout << "\t\t\t\t\t\t\t\t   "                  << username<< "\t\t\t\t\t"                   <<endl;
        cout << "\t\t\t\t\t|__________________________________________________________________|" << endl;
        cout <<"\n\n" << endl;
    } 
    else 
    {
        cout << "\t\t\t\t\t\t\t     Error: Unable to open file for writing.\n";
    }
    outfile.close();
}

/*this code is to login the customer
the customer will enter the username and password
if the username and password is correct, the login succesfull message will be displayed
if the username and password is incorrect, the invalid username or password message will be displayed
this function will be used in main_menu.cpp*/
void LoginRegisterForgot::loginCustomer() 
{
    string username, password, storedPassword;

    cout << "\t\t\t\t\t\t\t     Enter username: ";
    cin.ignore();
    getline(cin, username);
    cout << "\t\t\t\t\t\t\t     Enter password: ";
    getline(cin, password);

    if (checkCustomerExists(username, storedPassword) && storedPassword == password) 
    {
        cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
        cout << "\t\t\t\t\t|                                                                  |" << endl;
        cout << "\t\t\t\t\t|                      Login succesfull!!!!                        |" << endl;
        cout << "\t\t\t\t\t|                         Welcome back!!                           |" << endl;
        cout << "\t\t\t\t\t\t\t\t  "                  << username<< "\t\t\t\t\t"                   <<endl;
        cout << "\t\t\t\t\t|__________________________________________________________________|" << endl;
        cout <<"\n\n" << endl;
    } else 

    {
        cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
        cout << "\t\t\t\t\t!                                                                  !" << endl;
        cout << "\t\t\t\t\t!                    Invalid Username or Password                  !" << endl;
        cout << "\t\t\t\t\t!                        Please try again later                    !" << endl;
        cout << "\t\t\t\t\t!__________________________________________________________________!" << endl;
        cout <<"\n\n" << endl;
    }
}

/*this code is to forgot the password
the customer will enter the username
if the username exists, the password will be displayed
if the username does not exists, the username not found message will be displayed
this function will be used in main_menu.cpp*/
void LoginRegisterForgot::forgotPassword() 
{
    string username, storedPassword;

    cout << "\t\t\t\t\t\t\t     Enter your username: ";
    cin.ignore();
    getline(cin, username);

    if (checkCustomerExists(username, storedPassword)) 
    {
        cout << "\t\t\t\t\t\t\t     Your password is: " << storedPassword << "\n\n\n";
    } 
    else 
    {
        cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
        cout << "\t\t\t\t\t!                                                                  !" << endl;
        cout << "\t\t\t\t\t!                       Username not found!!                       !" << endl;
        cout << "\t\t\t\t\t!__________________________________________________________________!" << endl;
        cout << "\n\n" << endl;
    }
}
