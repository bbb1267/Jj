#ifndef BANK_H
#define BANK_H

#include <vector>
#include <string>
#include "Client.h"
#include "Account.h"
#include "Transaction.h"

class Bank {
private:
    std::string name;
    std::vector<Client> clients;
    std::vector<Account*> accounts;
    std::vector<Transaction> transactions;
public:
    Bank(std::string name);
    void addClient(const Client& client);
    Account* createAccount(Client& client, std::string type);
    void performTransaction(Transaction& transaction);
    void cancelTransaction(int transactionId);
    void showClients() const;
    const std::vector<Account*>& getAccounts() const; // Добавлен метод для доступа к счетам
};

#endif