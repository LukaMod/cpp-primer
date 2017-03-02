#ifndef EX7_57_H_
#define EX7_57_H_

#include <string>

class Account
{
  public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double);

  private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate();
};

double Account::interestRate = initRate();

void Account::rate(double newRate)
{
    interestRate = newRate;
}

#endif