/*                         GROUP 35
  ____________________________________________________________
  |                                      |                   |
  |              NAME                    |      Matric No    |
  |______________________________________|___________________|
  |  AHMAD SYAHIRAN ZAKWAN BIN KARMAH    |      23303512     |
  |            TANG JIN SHEN             |      23301943     |
  |        GARETT KHOO BOO ZHENG         |      23301528     |
  |    MUHAMAD ALIFF NAJMI BIN ADENAN    |      23303539     |
  |  NURUL FATIHA ARMANI BINTI MUHAMMAD  |      23302501     | 
  |               NIZAM                  |                   |
  | NUR FARZANA IZZATI BINTI BARZAN SHAH |      23303059     |
  |______________________________________|___________________|
  TITLE: AIRLINE RESERVATION SYSTEM  
  Purpose: To provide a system that allows users to reserve airline with different class and seats, view ticket bills, and cancel reservations.
*/

/*Programmer name: TANG JIN SHEN
  Matric number : 23301943
  Function of this cpp file - to call the function from all cpp file and this system will just run in main.cpp file
*/
#include "LoginRegisterForgot.hpp"
#include "main_menu.hpp"
#include "welcome.hpp"
#include <iostream>

using namespace std;

int main() 
{
    welcomePage();
    LoginRegisterForgot loginregisterforgot;
    mainMenu(loginregisterforgot);
    return 0;
}
