#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>

#include "Ticket.h"


class Airplane {
private:
    std::string date;
    std::string flightNumber;
    int seatsPerRow;
    int totalRows;
    std::unordered_map<int, int> priceRange;
    std::vector<bool> seatsAvailability;
    std::unordered_map<std::string, int> seatToTicket;
    static int nextTicketId;


    std::string indexToSeat(int index) const;

    int seatToIndex(const std::string &seatId) const;

public:
    Airplane(const std::string &date, const std::string &flightNumber, int seatsPerRow, int totalRows,
             const std::unordered_map<int, int> &priceRange);

    int bookSeatGetId(const std::string &seat);

    void unbookSeat(const std::string &seat);

    void showAvailableSeatsWithPrices() const;

    std::vector<int> getBookedSeatsId() const;

    friend std::ostream &operator<<(std::ostream &out, const Airplane &airplane);

    ~Airplane();
};
