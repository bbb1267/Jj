#ifndef MARKET_H
#define MARKET_H
#include <vector>
#include <string>
#include "Product.h"

class Market {
public:
    std::string marketName;
    std::vector<Product> inventory;

    Market(std::string name);
    void addItem(std::string name, double price, int stock);
    double findItemPrice(std::string itemName);
    void listItems();
};
#endif