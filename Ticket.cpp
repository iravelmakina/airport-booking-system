#include "Ticket.h"


Ticket::Ticket(const std::string &username, const std::string &date, const std::string &flightNumber,
               const std::string &seat, int price, bool isBooked) : username(username), date(date),
                                                                    flightNumber(flightNumber), seat(seat),
                                                                    price(price),
                                                                    isBooked(isBooked) {
    static int nextId = 1;
    id = nextId++;
}


bool Ticket::isNotAvailable() const {
    return isBooked();
}

void Ticket::returnTicket() {
    std::cout << "Ticket with ID " << id << " is returned." << std::endl;
    isBooked = false;
}


std::ostream &operator<<(std::ostream &out, const Ticket &ticket) {
    out << "Ticket(ID: " << ticket.id << ", Username: " << ticket.username << ", Date: " << ticket.date
            << ", Flight Number: " << ticket.flightNumber << ", Seat: " << ticket.seat
            << ", Price: $" << ticket.price << ", Status: " << (ticket.isBooked ? "Booked" : "Unbooked") << ")";
    return out;
}


Ticket::~Ticket() = default;
