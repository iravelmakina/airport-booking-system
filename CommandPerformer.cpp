#include <iostream>

#include "CommandPerformer.h"

CommandPerformer::CommandPerformer(std::unique_ptr<Registry> registry) : registry(std::move(registry)) {
}


void CommandPerformer::check(const std::string &date, const std::string &flightNumber) const {
    // memory: O(n), time: O(n)
    const Airplane *airplane = getAirplaneOrError(date, flightNumber);
    if (airplane) {
        const std::string availableSeats = airplane->getAvailableSeatsWithPrices();

        if (!availableSeats.empty()) {
            std::cout << availableSeats << std::endl;
        } else {
            std::cout << "No available seats for flight " << flightNumber << " on date " << date << std::endl;
        }
    }
}


void CommandPerformer::book(const std::string &date, const std::string &flightNumber, const std::string &seat,
                            const std::string &username) const {
    // memory: O(1), time: O(1)
    Airplane *airplane = getAirplaneOrError(date, flightNumber);
    if (airplane) {
        const int bookedTicketId = airplane->bookSeatGetId(seat);
        if (bookedTicketId != -1) {
            const Ticket ticket(bookedTicketId, username, date, flightNumber, seat, airplane->getSeatPrice(seat));
            registry->addTicket(bookedTicketId, ticket);
            registry->addUserTicket(username, bookedTicketId);
            std::cout << "Confirmed with ID " << bookedTicketId << std::endl;
        } else {
            std::cerr << "Error: Seat " << seat << " is already booked." << std::endl;
        }
    }
}


void CommandPerformer::unbook(const int id) const {
    // memory: O(1), time: O(n)
    const Ticket *ticket = registry->getTicket(id);
    if (ticket) {
        std::cout << "Confirmed " << ticket->price << "$" << " refund for " << ticket->username << std::endl;
        Airplane *airplane = getAirplaneOrError(ticket->date, ticket->flightNumber);
        if (airplane) {
            if (airplane->tryUnbookSeat(ticket->seat)) {
                registry->removeTicket(id);
                registry->removeUserTicket(ticket->username, ticket->id);
            } else {
                std::cerr << "Error: Seat " << ticket->seat << " was not booked and cannot be unbooked." << std::endl;
            }
        }
    } else {
        std::cerr << "Error: Ticket with ID " << id << " not found." << std::endl;
    }
}


void CommandPerformer::view(const std::string &username) const {
    // memory: O(1), time: O(n)
    const std::unordered_set<int> ticketsId = registry->getUserTickets(username);
    if (!ticketsId.empty()) {
        int index = 1;
        for (const int id: ticketsId) {
            const Ticket *ticket = registry->getTicket(id);
            std::cout << index++ << ". Flight " << ticket->flightNumber << ", " << ticket->date << ", seat " <<
                    ticket->
                    seat << ", price " << ticket->price << "$" << std::endl;
        }
    } else {
        std::cerr << "Error: No tickets found for user " << username << std::endl;
    }
}


void CommandPerformer::view(const int id) const {
    // memory: O(1), time: O(1)
    const Ticket *ticket = registry->getTicket(id);
    if (ticket) {
        std::cout << "Flight " << ticket->flightNumber << ", " << ticket->date << ", seat " << ticket->seat << ", " <<
                ticket->price << "$" << std::endl;
    } else {
        std::cerr << "Error: Ticket with ID " << id << " not found." << std::endl;
    }
}


void CommandPerformer::view(const std::string &date, const std::string &flightNumber) const {
    // memory: O(n), time: O(n)
    const Airplane *airplane = getAirplaneOrError(date, flightNumber);
    if (airplane) {
        const std::vector<int> seatsId = airplane->getBookedSeatsId();
        if (!seatsId.empty()) {
            for (auto const id: seatsId) {
                const Ticket *ticket = registry->getTicket(id);
                std::cout << ticket->seat << " " << ticket->username << " " << ticket->price << "$" << std::endl;
            }
        } else {
            std::cerr << "Error: No seats are booked for flight " << flightNumber << " on date " << date << std::endl;
        }
    }
}


Airplane *CommandPerformer::getAirplaneOrError(const std::string &date, const std::string &flightNumber) const {
    // memory: O(1), time: O(1)
    Airplane *airplane = registry->getAirplane(date, flightNumber);
    if (!airplane) {
        std::cerr << "Error: Airplane not found for date " << date << " and flight number " << flightNumber <<
                std::endl;
    }
    return airplane;
}
