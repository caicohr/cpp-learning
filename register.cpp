#include <iostream>
#include <string>
#include <iomanip>

#include "register.h"

using namespace std;

Register::Register(float b) {
    balance = b;
}

void Register::getMoney() {
    cout << "The register has $:" <<setprecision(2)<<fixed<<balance << "."<<endl;
}

void Register::addMoney(float p) {
    balance = balance + p;
}

void Register::deductMoney(float m) {
    balance = balance - m;
}