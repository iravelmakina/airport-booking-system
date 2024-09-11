#include "CommandPerformer.h"

CommandPerformer::CommandPerformer(Registry &registry) : registry(registry) {
}

void CommandPerformer::check(const std::string &date, const std::string &flightNumber) const { // memory: O(1), time: O(n)
    const Airplane *airplane = getAirplaneOrError(date, flightNumber);
    airplane->showAvailableSeatsWithPrices();
}


void CommandPerformer::book(const std::string &date, const std::string &flightNumber, const std::string &seat,
                            const std::string &username) const { // memory: O(1), time: O(1)
    // it does not modify command performer
    Airplane *airplane = getAirplaneOrError(date, flightNumber);
    int bookedTicketId = airplane->bookSeatGetId(seat);
    if (bookedTicketId != -1) {
        Ticket ticket(bookedTicketId, username, date, flightNumber, seat, airplane->getSeatPrice(seat));
        registry.addTicket(bookedTicketId, ticket);
        registry.addUserTicket(username, bookedTicketId);
        std::cout << "Confirmed with ID " << bookedTicketId << std::endl;
    } else {
        std::cerr << "Error: Seat " << seat << " is already booked." << std::endl;
    }
}


void CommandPerformer::unbook(int id) const { // memory: O(1), time: O(n)
    const Ticket *ticket = registry.getTicket(id);
    if (ticket) {
        std::cout << "Confirmed " << ticket->price << "$" << " refund for " << ticket->username << std::endl;
        registry.getAirplane(ticket->date, ticket->flightNumber)->unbookSeat(ticket->seat);
        registry.removeTicket(id);
        registry.removeUserTicket(ticket->username, ticket->id); // getters
    } else {
        std::cerr << "Error: Ticket with ID " << id << " not found." << std::endl;
    }
}


void CommandPerformer::view(const std::string &username) const { // memory: O(1), time: O(n)
    std::unordered_set<int> ticketsId = registry.getUserTickets(username);
    if (!ticketsId.empty()) {
        int index = 1;
        for (int id : ticketsId) {
            const Ticket *ticket = registry.getTicket(id);
            std::cout <<  index++ << ". Flight " << ticket->flightNumber << ", " << ticket->date << ", seat " <<
                    ticket->
                    seat << ", price " << ticket->price << "$" << std::endl;
        }
    } else {
        std::cerr << "Error: No tickets found for user " << username << std::endl;
    }
}


void CommandPerformer::view(int id) const { // memory: O(1), time: O(1)
    const Ticket *ticket = registry.getTicket(id);
    if (ticket) {
        std::cout << "Flight " << ticket->flightNumber << ", " << ticket->date << ", seat " << ticket->seat << ", " <<
                ticket->price << "$" << std::endl;
    } else {
        std::cerr << "Error: Ticket with ID " << id << " not found." << std::endl;
    }
}


void CommandPerformer::view(const std::string &date, const std::string &flightNumber) const { // memory: O(1), time: O(n + m)
    const Airplane *airplane = getAirplaneOrError(date, flightNumber);
    const std::vector<int> seatsId = airplane->getBookedSeatsId();
    if (!seatsId.empty()) {
        for (auto const id: seatsId) { // error
            const Ticket *ticket = registry.getTicket(id);
            std::cout << ticket->seat << " " << ticket->username << " " << ticket->price << "$" << std::endl;
        }
    } else {
        std::cerr << "Error: No seats are booked for flight " << flightNumber << " on date " << date << std::endl;
    }
}


Airplane *CommandPerformer::getAirplaneOrError(const std::string &date, const std::string &flightNumber) const { // memory: O(1), time: O(1)
    Airplane *airplane = registry.getAirplane(date, flightNumber);
    if (!airplane) {
        std::cerr << "Error: Airplane not found for date " << date << " and flight number " << flightNumber <<
                std::endl;
    }
    return airplane;
}
