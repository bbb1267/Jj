#include "Buyer.h"
#include <iostream>

Buyer::Buyer(std::string name, double balance) : buyerName(name), accountBalance(balance) {}

bool Buyer::buyProduct(Market& market, std::string itemName, int amount) {
    for (auto& item : market.inventory) {
        if (item.itemName == itemName && item.itemStock >= amount) {
            double totalCost = item.itemPrice * amount;
            if (accountBalance >= totalCost) {
                accountBalance -= totalCost;
                item.itemStock -= amount;
                std::cout << buyerName << " купил " << amount << " " << itemName << " в " << market.marketName << std::endl;
                return true;
            }
            else {
                std::cout << "Недостаточно средств у " << buyerName << std::endl;
                return false;
            }
        }
    }
    std::cout << "Товар не найден или недостаточно в наличии в " << market.marketName << std::endl;
    return false;
}

void Buyer::showBalance() {
    std::cout << "Баланс " << buyerName << " - " << accountBalance << std::endl;
} 