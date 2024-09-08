#include "Airplane.h"

Airplane::Airplane(const std::string &date, const std::string &flightNumber, int seatsPerRow,
                   std::vector<bool> &seatsAvailability, const std::map<std::string, int> &priceRange,
                   std::map<std::string, Ticket> &tickets) : date(date), flightNumber(flightNumber),
                                                             seatsPerRow(seatsPerRow),
                                                             seatsAvailability(seatsAvailability),
                                                             priceRange(priceRange), tickets(tickets) {
}


Airplane::~Airplane() = default;
