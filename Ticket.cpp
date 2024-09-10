#include "Ticket.h"


Ticket::Ticket(int id, const std::string &username, const std::string &date, const std::string &flightNumber,
               const std::string &seat, int price) : id(id), username(username), date(date),
                                                     flightNumber(flightNumber), seat(seat),
                                                     price(price) { // const for int?
}


std::ostream &operator<<(std::ostream &out, const Ticket &ticket) {
    out << "Ticket(ID: " << ticket.id << ", Username: " << ticket.username << ", Date: " << ticket.date
            << ", Flight Number: " << ticket.flightNumber << ", Seat: " << ticket.seat
            << ", Price: $" << ticket.price << ")";
    return out;
}
