#include "Account.h"

Account::Account(std::string id, double initialBalance) : accountId(id), balance(initialBalance) {}

void Account::deposit(double amount) {
    balance += amount;
}

bool Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

double Account::getBalance() const {
    return balance;
}

std::string Account::getAccountId() const {
    return accountId;
}

double DebitAccount::getBalance() const {
    return balance;
}

double DepositAccount::getBalance() const {
    return balance;
}

double CreditAccount::getBalance() const {
    return balance;
}

DebitAccount::DebitAccount(std::string id, double initialBalance) : Account(id, initialBalance) {}

DepositAccount::DepositAccount(std::string id, double initialBalance, int lockPeriod) : Account(id, initialBalance), lockPeriod(lockPeriod) {}

CreditAccount::CreditAccount(std::string id, double initialBalance, double creditLimit, double fee)
    : Account(id, initialBalance), creditLimit(creditLimit), fee(fee) {}

bool CreditAccount::withdraw(double amount) {
    if (balance + creditLimit >= amount) {
        balance -= amount + fee;
        return true;
    }
    return false;
}