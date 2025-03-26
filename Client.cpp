#include "Client.h"

Client::Client(std::string firstName, std::string lastName, std::string passport, std::string address)
    : firstName(firstName), lastName(lastName), passport(passport), address(address) {}

std::string Client::getFullName() const {
    return firstName + " " + lastName;
}