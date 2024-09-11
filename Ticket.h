#pragma once
#include <iostream>
#include <vector>

class Ticket {
public:
    int id;
    std::string username;
    std::string date;
    std::string flightNumber;
    std::string seat;
    int price;

    Ticket(int id, const std::string &username, const std::string &date, const std::string &flightNumber,
           const std::string &seat, int price); // i have const and & everywhere in constructor, except int. why? ask const before


    friend std::ostream &operator<<(std::ostream &out, const Ticket &ticket); // non-member?? can i use friend
};
