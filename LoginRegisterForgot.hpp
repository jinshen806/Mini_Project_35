#ifndef LOGINREGISTERFORGOT_HPP
#define LOGINREGISTERFORGOT_HPP

#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

class LoginRegisterForgot 
{

public:

    void registerCustomer();
    void loginCustomer();
    void forgotPassword();

private:

    const string customerFile = "customer_data.txt";
    bool checkCustomerExists(const string& username, string& password);

};

#endif
