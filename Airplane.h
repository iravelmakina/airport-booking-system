#ifndef AIRPLANE_H
#define AIRPLANE_H
#include <iostream>
#include <map>
#include <vector>

#include "Ticket.h"


class Airplane {
    std::string date;
    std::string flightNumber;
    int seatsPerRow;
    std::vector<bool> seatsAvailability;
    std::map<std::string, int> priceRange;
    std::map<std::string, Ticket> tickets;

public:
    Airplane(const std::string &date, const std::string &flightNumber, int seatsPerRow,
             std::vector<bool> &seatsAvailability, const std::map<std::string, int> &priceRange,
             std::map<std::string, Ticket> &tickets);

    void calculateTicketPrice();
    friend std::ostream &operator<<(std::ostream &out, const Airplane &airplane);

    ~Airplane();
};


#endif //AIRPLANE_H
