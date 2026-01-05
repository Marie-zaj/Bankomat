#include <iostream>
#include "Bankomat.h"
using namespace std;

int main() {
    Bankomat atm(1, 100, 5000);

    atm.loadMoney(10, 10, 5, 2);

    atm.printInfo();

    atm.withdraw(1800);

    atm.printInfo();

    return 0;
}