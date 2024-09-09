#ifndef TICKET_H
#define TICKET_H
#include <iostream>
#include <vector>


class Ticket {
    int id;
    std::string username;
    std::string date;
    std::string flightNumber;
    std::string seat;
    int price;
    bool isBooked;

public:
    Ticket();

    Ticket(int id, const std::string &username, const std::string &date, const std::string &flightNumber,
           const std::string &seat, int price, bool isBooked = true);

    void book();
    void unbook();
    friend std::ostream &operator<<(std::ostream &out, const Ticket &ticket);

    ~Ticket();
};



#endif //TICKET_H
