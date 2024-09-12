#pragma once
#include <vector>

#include <iostream>

class Ticket {
public:
    int id;
    std::string username;
    std::string date;
    std::string flightNumber;
    std::string seat;
    int price;

    Ticket() = default;

    Ticket(int id, const std::string &username, const std::string &date, const std::string &flightNumber,
           const std::string &seat, int price);
};

std::ostream &operator<<(std::ostream &out, const Ticket &ticket);
