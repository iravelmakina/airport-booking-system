#include "Registry.h"
#include <unordered_map>

#include "Ticket.h"

// errors
void Registry::addAirplane(const std::string &date, const std::string &flightNumber, const Airplane &airplane) {
    const std::string dateFlightNumber = date + "_" + flightNumber; // Concatenate the date and flightNumber
    airflightsRegistry[dateFlightNumber] = airplane;
} // memory: O(1), time: O(1)


Airplane *Registry::getAirplane(const std::string &date, const std::string &flightNumber) {
    const auto ptr = airflightsRegistry.find(date + "_" + flightNumber);
    if (ptr != airflightsRegistry.end()) {
        return &ptr->second;
    }
    return nullptr;
} // memory: O(1), time: O(1)


void Registry::addTicket(const int ticketId, const Ticket &ticket) {
    ticketsRegistry[ticketId] = ticket;
} // memory: O(1), time: O(1)


void Registry::removeTicket(const int ticketId) {
    ticketsRegistry.erase(ticketId);
} // memory: O(1), time: O(1)


const Ticket *Registry::getTicket(const int ticketId) const {
    const auto ptr = ticketsRegistry.find(ticketId);
    if (ptr != ticketsRegistry.end()) {
        return &ptr->second;
    }
    return nullptr;
} // memory: O(1), time: O(1)


void Registry::addUserTicket(const std::string &username, const int id) {
    userToTicket[username].insert(id);
} // memory: O(1), time: O(1)


void Registry::removeUserTicket(const std::string &username, const int id) {
    const auto ptr = userToTicket.find(username);
    if (ptr != userToTicket.end()) {
        auto &ticketsId = ptr->second;
        ticketsId.erase(id);
        if (ticketsId.empty()) {
            userToTicket.erase(ptr);
        }
    }
} // memory: O(1), time: O(1)


std::unordered_set<int> Registry::getUserTickets(const std::string &username) const {
    const auto ptr = userToTicket.find(username);
    if (ptr != userToTicket.end()) {
        return ptr->second;
    }
    return {};
} // memory: O(1), time: O(1)
