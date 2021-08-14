//
// Created by honker on 2021/8/14.
//

#ifndef CPPTRAIN_ACCOUNT_H
#define CPPTRAIN_ACCOUNT_H
#include <bits/stdc++.h>
using namespace std;

class Account {
public:
    void calculate() {amount += amount * interestRate; }
    static double rate(){return interestRate; }
    static void rate(double r);

private:
    string owner;
    double amount;
    static double interestRate;
    static double initRate();
};


#endif //CPPTRAIN_ACCOUNT_H
