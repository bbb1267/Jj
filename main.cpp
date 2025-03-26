#include <iostream>
#include "Bank.h"
#include "Client.h"
#include "Transaction.h"

void displayMenu() {
    std::cout << "\nBanking System Menu:\n";
    std::cout << "1. Create Client\n";
    std::cout << "2. Create Account\n";
    std::cout << "3. Perform Transaction\n";
    std::cout << "4. Cancel Transaction\n";
    std::cout << "5. View Clients\n";
    std::cout << "6. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    Bank bank("MyBank");
    int choice;
    std::vector<Client> clients;
    std::vector<Transaction> transactions;
    int transactionCounter = 0;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string firstName, lastName;
            std::cout << "Enter first name: ";
            std::cin >> firstName;
            std::cout << "Enter last name: ";
            std::cin >> lastName;
            clients.emplace_back(firstName, lastName);
            bank.addClient(clients.back());
            std::cout << "Client added successfully.\n";
            break;
        }
        case 2: {
            if (clients.empty()) {
                std::cout << "No clients available. Create a client first.\n";
                break;
            }

            std::cout << "Select a client:\n";
            for (size_t i = 0; i < clients.size(); ++i) {
                std::cout << i << ": " << clients[i].getFullName() << "\n";
            }

            int clientIndex;
            std::cout << "Enter client index: ";
            std::cin >> clientIndex;

            if (clientIndex < 0 || clientIndex >= static_cast<int>(clients.size())) {
                std::cout << "Invalid client index.\n";
                break;
            }

            std::string type;
            std::cout << "Enter account type (debit/deposit/credit): ";
            std::cin >> type;

            bank.createAccount(clients[clientIndex], type);
            std::cout << "Account created successfully.\n";
            break;
        }

        case 3: {
            std::string fromId, toId;
            double amount;
            std::cout << "Enter sender account ID: ";
            std::cin >> fromId;
            std::cout << "Enter recipient account ID: ";
            std::cin >> toId;
            std::cout << "Enter amount: ";
            std::cin >> amount;
            Account* from = nullptr;
            Account* to = nullptr;
            for (auto& acc : bank.getAccounts()) {
                if (acc->getAccountId() == fromId) from = acc;
                if (acc->getAccountId() == toId) to = acc;
            }
            if (from && to) {
                transactions.emplace_back(++transactionCounter, from, to, amount);
                bank.performTransaction(transactions.back());
                std::cout << "Transaction completed successfully.\n";
            }
            else {
                std::cout << "Invalid account IDs.\n";
            }
            break;
        }
        case 4: {
            int transactionId;
            std::cout << "Enter transaction ID to cancel: ";
            std::cin >> transactionId;
            bank.cancelTransaction(transactionId);
            std::cout << "Transaction canceled successfully.\n";
            break;
        }
        case 5:
            bank.showClients();
            break;
        case 6:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid option. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}