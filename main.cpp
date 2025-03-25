#include <iostream>
#include <vector>
#include "Market.h"
#include "Buyer.h"

void displayMenu() {
    std::cout << "Меню:" << std::endl;
    std::cout << "1)Создать магазин" << std::endl;
    std::cout << "2)Зарегистрировать товар" << std::endl;
    std::cout << "3)Купить товар" << std::endl;
    std::cout << "4)Показать баланс покупателя" << std::endl;
    std::cout << "5)Вывести товары магазина" << std::endl;
    std::cout << "0)Выход" << std::endl;
}

int main() {
    std::setlocale(LC_ALL, "rus");
    std::vector<Market> markets;
    Buyer buyer("Богданыч", 35.0);

    int selection;
    do {
        displayMenu();
        std::cout << "Выбор: ";
        std::cin >> selection;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод." << std::endl;
            continue;
        }

        if (selection == 1) {
            std::string marketName;
            std::cout << "Введите название магазина: ";
            std::cin >> marketName;
            markets.emplace_back(marketName);
        }
        else if (selection == 2) {
            std::string marketName, itemName;
            double price;
            int stock;
            std::cout << "Введите название магазина: ";
            std::cin >> marketName;
            std::cout << "Введите название товара: ";
            std::cin >> itemName;
            std::cout << "Введите цену: ";
            std::cin >> price;
            std::cout << "Введите количество: ";
            std::cin >> stock;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Некорректный ввод." << std::endl;
                continue;
            }

            for (auto& market : markets) {
                if (market.marketName == marketName) {
                    market.addItem(itemName, price, stock);
                    break;
                }
            }
        }
        else if (selection == 3) {
            std::string marketName, itemName;
            int amount;
            std::cout << "Введите магазин: ";
            std::cin >> marketName;
            std::cout << "Введите товар: ";
            std::cin >> itemName;
            std::cout << "Введите количество: ";
            std::cin >> amount;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Некорректный ввод." << std::endl;
                continue;
            }

            for (auto& market : markets) {
                if (market.marketName == marketName) {
                    buyer.buyProduct(market, itemName, amount);
                    break;
                }
            }
        }
        else if (selection == 4) {
            buyer.showBalance();
        }
        else if (selection == 5) {
            for (auto& market : markets) {
                market.listItems();
            }
        }
    } while (selection != 0);
    return 0;
}