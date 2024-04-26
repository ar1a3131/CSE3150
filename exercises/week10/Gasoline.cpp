#include "Gasoline.h"
#include <iostream>

using namespace std;

Gasoline::Gasoline(std::string name) : Vehicle(name, 0) {
    cout << "Constructor: Gasoline" << endl;
}

Gasoline::~Gasoline() {
    cout << "Destructor: Gasoline" << endl;
}

void Gasoline::Start() {
    cout << "Gasoline start" << endl;
}

void Gasoline::Stop() {
    cout << "Gasoline stop" << endl;
}

double Gasoline::CostOfFuel() {

    return 0.15;
}

double Gasoline::FuelEfficiency() {
    return 30.0; // placeholder for gasoline vehicle's fuel efficiency
}
