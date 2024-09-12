#pragma once
#include <unordered_map>
#include <vector>


class Airplane {
    std::unordered_map<int, int> priceRange;
    std::vector<bool> seatsAvailability;
    std::unordered_map<std::string, int> seatToTicket;
    static int nextTicketId;


    std::string indexToSeat(int index) const;

    int seatToIndex(const std::string &seatId) const;

public:
    std::string date;
    std::string flightNumber;
    int seatsPerRow;
    int totalRows;

    Airplane() = default;

    Airplane(const std::string &date, const std::string &flightNumber, int seatsPerRow, int totalRows,
             const std::unordered_map<int, int> &priceRange);

    int getSeatPrice(const std::string &seat) const;

    std::string getAvailableSeatsWithPrices() const;

    int bookSeatGetId(const std::string &seat);

    bool tryUnbookSeat(const std::string &seat);

    std::vector<int> getBookedSeatsId() const;
};

std::ostream &operator<<(std::ostream &out, const Airplane &airplane);
