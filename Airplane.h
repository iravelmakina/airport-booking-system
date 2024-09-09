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
             std::map<std::string, Ticket> tickets = {});

    void createTicket(int id, const std::string &username, const std::string &date, const std::string &flightNumber,
                  const std::string &seat, int price, bool status);

    int calculateSeatPrice(const std::string &seat) const;

    std::string indexToSeat(int index) const;

    void showAvailableSeatsWithPrices() const;

    friend std::ostream &operator<<(std::ostream &out, const Airplane &airplane);

    ~Airplane();
};


#endif //AIRPLANE_H
