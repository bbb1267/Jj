#include "Bank.h"
#include "Account.h"
#include <iostream>

Bank::Bank(std::string name) : name(name) {}

void Bank::addClient(const Client& client) {
    clients.push_back(client);
}

Account* Bank::createAccount(Client& client, std::string type) {
    Account* account = nullptr;
    if (type == "debit") {
        account = new DebitAccount("A" + std::to_string(accounts.size() + 1), 0);
    }
    else if (type == "deposit") {
        account = new DepositAccount("A" + std::to_string(accounts.size() + 1), 0, 12);
    }
    else if (type == "credit") {
        account = new CreditAccount("A" + std::to_string(accounts.size() + 1), 0, 1000, 10);
    }
    if (account) accounts.push_back(account);
    return account;
}

void Bank::performTransaction(Transaction& transaction) {
    transaction.execute();
    transactions.push_back(transaction);
}

void Bank::cancelTransaction(int transactionId) {
    for (auto it = transactions.begin(); it != transactions.end(); ++it) {
        if (it->getId() == transactionId) {
            it->rollback();
            transactions.erase(it);
            break;
        }
    }
}

void Bank::showClients() const {
    for (const auto& client : clients) {
        std::cout << client.getFullName() << std::endl;
    }
}

const std::vector<Account*>& Bank::getAccounts() const {
    return accounts;
}
