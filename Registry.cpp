#include "Registry.h"
#include <iostream>
#include <unordered_map>

void Registry::addAirplane(const std::string &date, const std::string &flightNumber, const Airplane &airplane) {
    airflightsRegistry[std::make_pair(date, flightNumber)] = airplane;
}


const Airplane *Registry::getAirplane(const std::string &date, const std::string &flightNumber) const { // validation, error checking
    auto ptr = airflightsRegistry.find(std::make_pair(date, flightNumber));
    if (ptr != airflightsRegistry.end()) {
        return &ptr->second;
    }
    return nullptr;
}


void Registry::addTicket(int ticketId, const Ticket &ticket) {
    ticketsRegistry[ticketId] = ticket;
}


void Registry::removeTicket(int ticketId) { // validation, error checking
    ticketsRegistry.erase(ticketId);
}


const Ticket *Registry::getTicket(int ticketId) const { // validation, error checking
    auto ptr = ticketsRegistry.find(ticketId);
    if (ptr != ticketsRegistry.end()) {
        return &ptr->second;
    }
    return nullptr;
}


void Registry::addUserTicket(const std::string &username, int id) {
    userToTicket[username].push_back(id);
}


void Registry::removeUserTicket(const std::string &username) { // validation, error checking
    userToTicket.erase(username);
}


const std::vector<int> Registry::getUserTickets(const std::string &username) const { // validation, error checking
    auto ptr = userToTicket.find(username);
    if (ptr != userToTicket.end()) {
        return ptr->second;
    }
    return {};
}









