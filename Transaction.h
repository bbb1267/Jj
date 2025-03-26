#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "Account.h"

class Transaction {
private:
    int transactionId;
    Account* from;
    Account* to;
    double amount;
public:
    Transaction(int id, Account* from, Account* to, double amount);
    void execute();
    void rollback();
    int getId() const;
};

#endif