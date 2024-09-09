#include "Airplane.h"

Airplane::Airplane(const std::string &date, const std::string &flightNumber, int seatsPerRow,
                   std::vector<bool> &seatsAvailability, const std::map<std::string, int> &priceRange,
                   std::map<std::string, Ticket> tickets) : date(date), flightNumber(flightNumber),
                                                            seatsPerRow(seatsPerRow),
                                                            seatsAvailability(seatsAvailability),
                                                            priceRange(priceRange), tickets(tickets) {}

void Airplane::createTicket(int id, const std::string &username, const std::string &date,
                            const std::string &flightNumber, const std::string &seat, int price, bool isBooked) {
    tickets[seat] = Ticket(id, username, date, flightNumber, seat, price, isBooked);
}


// also good to make a sep vector with booked seats
void Airplane::showAvailableSeatsWithPrices() const {
    for (size_t i = 0; i < seatsAvailability.size(); i++) {
        if (seatsAvailability[i]) {
            std::string seat = indexToSeat(static_cast<int>(i));
            std::cout << seat << " " << calculateSeatPrice(seat) << "$" << ", ";
        }
    }
}


// can be optimized to binary search
int Airplane::calculateSeatPrice(const std::string &seat) const {
    int rowNumber = std::stoi(seat.substr(0, seat.size() - 1));

    for (const auto &range: priceRange) {
        std::string rangeStr = range.first;
        int price = range.second;

        size_t dashPos = rangeStr.find('-');
        int startRange = std::stoi(rangeStr.substr(0, dashPos));
        int endRange = std::stoi(rangeStr.substr(dashPos + 1));

        if (rowNumber >= startRange && rowNumber <= endRange) {
            return price;
        }
    }
    return -1;
}


std::string Airplane::indexToSeat(int index) const {
    int rowNumber = (index / seatsPerRow) + 1;
    char seatLetter = static_cast<char>('A' + (index % seatsPerRow));
    return std::to_string(rowNumber) + seatLetter;
} // perfect


std::ostream &operator<<(std::ostream &out, const Airplane &airplane) {
    out << "Airplane(Date: " << airplane.date << ", Flight Number: " << airplane.flightNumber << ", Seats per Row: " <<
            airplane.seatsPerRow << ")";
    return out;
}


Airplane::~Airplane() = default;
