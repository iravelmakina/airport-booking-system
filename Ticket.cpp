#include "Ticket.h"

Ticket::Ticket() : id(0), username(" "), date(" "), flightNumber(" "), seat(" "), price(0), isBooked(false) {};

Ticket::Ticket(int id, const std::string &username, const std::string &date, const std::string &flightNumber,
               const std::string &seat, int price, bool isBooked) : id(id), username(username), date(date),
                                                                    flightNumber(flightNumber), seat(seat),
                                                                    price(price),
                                                                    isBooked(isBooked) {}

void Ticket::book() {
    std::cout << "Ticket with ID " << id << " is booked." << std::endl;
    isBooked = true;
}

void Ticket::unbook() {
    std::cout << "Ticket with ID " << id << " is unbooked." << std::endl;
    isBooked = false;
}

std::ostream &operator<<(std::ostream &out, const Ticket &ticket) {
    out << "Ticket(ID: " << ticket.id << ", Username: " << ticket.username << ", Date: " << ticket.date
            << ", Flight Number: " << ticket.flightNumber << ", Seat: " << ticket.seat
            << ", Price: $" << ticket.price << ", Status: " << (ticket.isBooked ? "Booked" : "Unbooked") << ")";
    return out;
}

Ticket::~Ticket() = default;
