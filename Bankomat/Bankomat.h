#pragma once
class Bankomat 
{
    int id;

    int count100;
    int count200;
    int count500;
    int count1000;

    int minPerDay;
    int maxPerDay;

 public:
    Bankomat(int id, int minPerDay, int maxPerDay);

    void loadMoney(int c100, int c200, int c500, int c1000);

    int getTotalMoney() const;

    bool withdraw(int amount);

    void printInfo() const;
};
