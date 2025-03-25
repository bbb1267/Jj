#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

class Product {
public:
    std::string itemName;
    double itemPrice;
    int itemStock;

    Product(std::string name, double price, int stock);
};

#endif