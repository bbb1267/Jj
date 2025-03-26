#ifndef CENTRALBANK_H
#define CENTRALBANK_H

#include <vector>
#include "Bank.h"

class CentralBank {
private:
    std::vector<Bank*> banks;
public:
    void registerBank(Bank* bank);
    void processInterBankTransaction(Transaction& transaction);
};

#endif