#include "Ticket.h"

Ticket::Ticket(int id, const std::string &username, const std::string &date, const std::string &flightNumber,
               const std::string &seat, int price, bool status) : id(id), username(username), date(date),
                                                                  flightNumber(flightNumber), seat(seat), price(price),
                                                                  status(status) {
}

void Ticket::book() {
    std::cout << "Ticket with ID " << id << " is booked." << std::endl;
    status = true;
}

void Ticket::unbook() {
    std::cout << "Ticket with ID " << id << " is unbooked." << std::endl;
    status = false;
}

std::ostream &operator<<(std::ostream &out, const Ticket &ticket) {
    out << "Ticket(ID: " << ticket.id << ", Username: " << ticket.username << ", Date: " << ticket.date
            << ", Flight Number: " << ticket.flightNumber << ", Seat: " << ticket.seat
            << ", Price: $" << ticket.price << ", Status: " << (ticket.status ? "Booked" : "Unbooked") << ")";
    return out;
}

Ticket::~Ticket() = default;
