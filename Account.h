#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
protected:
    std::string accountId;
    double balance;
public:
    Account(std::string id, double initialBalance);
    virtual void deposit(double amount);
    virtual bool withdraw(double amount);
    virtual double getBalance() const = 0;
    std::string getAccountId() const;
};

class DebitAccount : public Account {
public:
    DebitAccount(std::string id, double initialBalance);
    double getBalance() const override;
};

class DepositAccount : public Account {
private:
    int lockPeriod;
public:
    DepositAccount(std::string id, double initialBalance, int lockPeriod);
    double getBalance() const override;
};

class CreditAccount : public Account {
private:
    double creditLimit;
    double fee;
public:
    CreditAccount(std::string id, double initialBalance, double creditLimit, double fee);
    bool withdraw(double amount) override;
    double getBalance() const override;
};


#endif