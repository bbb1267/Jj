#ifndef BUYER_H
#define BUYER_H
#include <string>
#include "Market.h"
#include <vector>

class Buyer {
public:
    std::string buyerName;
    double accountBalance;
    std::vector<std::string> wishList;

    Buyer(std::string name, double balance);
    bool buyProduct(Market& market, std::string itemName, int amount);
    void showBalance();
};
#endif