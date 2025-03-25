#include "Market.h"
#include <iostream>

Market::Market(std::string name) : marketName(name) {}

void Market::addItem(std::string name, double price, int stock) {
    inventory.push_back(Product(name, price, stock));
}

double Market::findItemPrice(std::string itemName) {
    for (const auto& item : inventory) {
        if (item.itemName == itemName) {
            return item.itemPrice;
        }
    }
    return std::numeric_limits<double>::max();
}

void Market::listItems() {
    std::cout << "Товары в " << marketName << ":\n";
    for (const auto& item : inventory) {
        std::cout << "- " << item.itemName << ", Цена: " << item.itemPrice << ", Количество: " << item.itemStock << "\n";
    }
}