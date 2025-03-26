#include "CentralBank.h"

void CentralBank::registerBank(Bank* bank) {
    banks.push_back(bank);
}

void CentralBank::processInterBankTransaction(Transaction& transaction) {
    transaction.execute();
}