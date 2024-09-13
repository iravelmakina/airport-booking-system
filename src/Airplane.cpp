#include <iostream>
#include <sstream>

#include "Airplane.h"

int Airplane::nextTicketId = 1;
// memory: O(n), time: O(n)
Airplane::Airplane(const std::string &date, const std::string &flightNumber, int seatsPerRow, int totalRows,
                   const std::unordered_map<int, int> &priceRange) : priceRange(priceRange),
                                                                     seatsAvailability(seatsPerRow * totalRows, true),
                                                                     date(date), flightNumber(flightNumber),
                                                                     seatsPerRow(seatsPerRow),
                                                                     totalRows(totalRows) {
}


int Airplane::getSeatPrice(const std::string &seat) const {
    // memory: O(1), time: O(1)
    const int row = std::stoi(seat.substr(0, seat.size() - 1));
    return priceRange.at(row);
}


std::string Airplane::getAvailableSeatsWithPrices() const {
    // memory: O(n), time: O(n)
    std::ostringstream result;
    for (int seatIndex = 0; seatIndex < seatsAvailability.size(); ++seatIndex) {
        if (seatsAvailability[seatIndex]) {
            result << indexToSeat(seatIndex) << " " << getSeatPrice(indexToSeat(seatIndex)) << "$, ";
        }
    }
    std::string output = result.str();
    if (!output.empty()) {
        output.pop_back();
        output.pop_back();
    }
    return output;
}


int Airplane::bookSeatGetId(const std::string &seat) {
    // memory: O(1), time: O(1)
    const int seatIndex = seatToIndex(seat);
    if (seatIndex == -1) {
        return -1;
    }

    if (seatsAvailability[seatIndex]) {
        seatsAvailability[seatIndex] = false;
        const int currentTicketId = nextTicketId++;
        seatToTicket[seat] = currentTicketId;
        return currentTicketId;
    }
    return -2;
}


bool Airplane::tryUnbookSeat(const std::string &seat) {
    // memory: O(1), time: O(1)
    const int seatIndex = seatToIndex(seat);

    if (!seatsAvailability[seatIndex]) {
        seatsAvailability[seatIndex] = true;
        seatToTicket.erase(seat);
        return true;
    }
    return false; // if seat is already free
}


std::vector<int> Airplane::getBookedSeatsId() const {
    // memory: O(n), time: O(n)
    std::vector<int> seatsIdVector;
    for (int seatIndex = 0; seatIndex < seatsAvailability.size(); ++seatIndex) {
        if (!seatsAvailability[seatIndex]) {
            std::string seatId = indexToSeat(seatIndex);
            seatsIdVector.push_back(seatToTicket.at(seatId));
        }
    }
    return seatsIdVector;
}


// helper to convert seat index to seat ID
std::string Airplane::indexToSeat(const int index) const {
    // memory: O(1), time: O(1)
    const int row = (index / seatsPerRow) + 1;
    const char seatLetter = static_cast<char>('A' + (index % seatsPerRow));
    return std::to_string(row) + seatLetter;
}


// helper to convert seat ID to seat index
int Airplane::seatToIndex(const std::string &seatId) const {
    // memory: O(1), time: O(1)
    const int row = std::stoi(seatId.substr(0, seatId.size() - 1));
    const char seatLetter = seatId.back();
    if (row < 1 || row > totalRows || seatLetter < 'A' || seatLetter >= 'A' + seatsPerRow) {
        return -1;
    }
    return (row - 1) * seatsPerRow + (seatLetter - 'A');
}


std::ostream &operator<<(std::ostream &out, const Airplane &airplane) {
    out << "Airplane(Date: " << airplane.date << ", Flight Number: " << airplane.flightNumber << ", Seats per Row: " <<
            airplane.seatsPerRow << ", Total Rows: " <<
            airplane.totalRows << ", Seats per Row: " <<
            airplane.seatsPerRow << ")";
    return out;
}
