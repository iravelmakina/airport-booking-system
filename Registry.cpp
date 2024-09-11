#include "Registry.h"
#include <iostream>
#include <unordered_map>

void Registry::addAirplane(const std::string &date, const std::string &flightNumber, const Airplane &airplane) {
    std::string dateFlightNumber = date + "_" + flightNumber;  // Concatenate the date and flightNumber
    airflightsRegistry[dateFlightNumber] = airplane;
} // memory: O(1), time: O(1)


Airplane *Registry::getAirplane(const std::string &date, const std::string &flightNumber) { // error checking
    auto ptr = airflightsRegistry.find(date + "_" + flightNumber);
    if (ptr != airflightsRegistry.end()) {
        return &ptr->second;
    }
    return nullptr;
} // memory: O(1), time: O(1)


void Registry::addTicket(int ticketId, const Ticket &ticket) {
    ticketsRegistry[ticketId] = ticket;
} // memory: O(1), time: O(1)


void Registry::removeTicket(int ticketId) { // error checking
    ticketsRegistry.erase(ticketId);
} // memory: O(1), time: O(1)


const Ticket *Registry::getTicket(int ticketId) const { // error checking
    auto ptr = ticketsRegistry.find(ticketId);
    if (ptr != ticketsRegistry.end()) {
        return &ptr->second;
    }
    return nullptr;
} // memory: O(1), time: O(1)


void Registry::addUserTicket(const std::string &username, int id) {
    userToTicket[username].insert(id);
} // memory: O(1), time: O(1)


void Registry::removeUserTicket(const std::string &username, int id) {
    // validation, error checking
    auto ptr = userToTicket.find(username);
    if (ptr != userToTicket.end()) {
        auto &ticketsId = ptr->second;
        ticketsId.erase(id);
        if (ticketsId.empty()) {
            userToTicket.erase(ptr);
        }
    }
} // memory: O(1), time: O(1)


const std::unordered_set<int> Registry::getUserTickets(const std::string &username) const { // validation, error checking
    auto ptr = userToTicket.find(username);
    if (ptr != userToTicket.end()) {
        return ptr->second;
    }
    return {};
} // memory: O(1), time: O(1)
