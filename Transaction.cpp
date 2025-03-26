#include "Transaction.h"

Transaction::Transaction(int id, Account* from, Account* to, double amount) : transactionId(id), from(from), to(to), amount(amount) {}

void Transaction::execute() {
    if (from->withdraw(amount)) {
        to->deposit(amount);
    }
}

void Transaction::rollback() {
    to->withdraw(amount);
    from->deposit(amount);
}

int Transaction::getId() const {
    return transactionId;
}