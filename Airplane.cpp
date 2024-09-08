#include "Airplane.h"

Airplane::Airplane(const std::string &date, const std::string &flightNumber, int seatsPerRow,
                   std::vector<bool> &seatsAvailability, const std::map<std::string, int> &priceRange,
                   std::map<std::string, Ticket> &tickets) : date(date), flightNumber(flightNumber),
                                                             seatsPerRow(seatsPerRow),
                                                             seatsAvailability(seatsAvailability),
                                                             priceRange(priceRange), tickets(tickets) {
}

void Airplane::calculateTicketPrice() {

}

std::ostream &operator<<(std::ostream &out, const Airplane &airplane) {
    out << "Airplane(Date: " << airplane.date << ", Flight Number: " << airplane.flightNumber << ", Seats per Row: " << airplane.seatsPerRow << ")";
    return out;
}

Airplane::~Airplane() = default;
