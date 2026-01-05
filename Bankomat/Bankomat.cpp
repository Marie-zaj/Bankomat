#include "Bankomat.h"
#include <iostream>
using namespace std;

Bankomat::Bankomat(int id, int minPerDay, int maxPerDay)
    : id(id),
    count100(0),
    count200(0),
    count500(0),
    count1000(0),
    minPerDay(minPerDay),
    maxPerDay(maxPerDay) {}

void Bankomat::loadMoney(int c100, int c200, int c500, int c1000) {
    count100 += c100;
    count200 += c200;
    count500 += c500;
    count1000 += c1000;
}

int Bankomat::getTotalMoney() const {
    return count100 * 100 +
        count200 * 200 +
        count500 * 500 +
        count1000 * 1000;
}

bool Bankomat::withdraw(int amount) {
    if (amount < minPerDay || amount > maxPerDay) {
        cout << "The amount does not correspond to the daily limits.\n";
        return false;
    }

    if (amount > getTotalMoney()) {
        cout << "There are not enough funds in the ATM.\n";
        return false;
    }

    int needed = amount;

    int take1000 = min(needed / 1000, count1000);
    needed -= take1000 * 1000;

    int take500 = min(needed / 500, count500);
    needed -= take500 * 500;

    int take200 = min(needed / 200, count200);
    needed -= take200 * 200;

    int take100 = min(needed / 100, count100);
    needed -= take100 * 100;

    if (needed != 0) {
        cout << "It is impossible to give the exact amount.\n";
        return false;
    }

    count1000 -= take1000;
    count500 -= take500;
    count200 -= take200;
    count100 -= take100;

    cout << "The withdrawal was successful.\n";
    return true;
}
void Bankomat::printInfo() const
{
    cout << "Balance of money in the ATM: " << getTotalMoney() << endl;
}