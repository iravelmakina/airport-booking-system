#pragma once
#include <iostream>
#include <vector>
// pragma

class Ticket {
    int id;
    std::string username;
    std::string date;
    std::string flightNumber;
    std::string seat;
    int price;

public:
    Ticket(int id, const std::string &username, const std::string &date, const std::string &flightNumber,
           const std::string &seat, int price);


    friend std::ostream &operator<<(std::ostream &out, const Ticket &ticket);

    ~Ticket();
};
