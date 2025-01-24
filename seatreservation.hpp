#ifndef SEATRESERVATION_HPP
#define SEATRESERVATION_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct FlightClass {
    string className;
    vector<string> seats;
    int rows;
    int columns;
};

class FlightReservationSystem;
void seatreservation(const string& username);

#endif