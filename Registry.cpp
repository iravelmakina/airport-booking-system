#include "Registry.h"
#include <iostream>
#include <unordered_map>

void Registry::addAirplane(const std::string &date, const std::string &flightNumber, const Airplane &airplane) {
    airflightsRegistry[std::make_pair(date, flightNumber)] = airplane;
}


Airplane *Registry::getAirplane(const std::string &date, const std::string &flightNumber) { // error checking
    auto ptr = airflightsRegistry.find(std::make_pair(date, flightNumber));
    if (ptr != airflightsRegistry.end()) {
        return &ptr->second;
    }
    return nullptr;
}


void Registry::addTicket(int ticketId, const Ticket &ticket) {
    ticketsRegistry[ticketId] = ticket;
}


void Registry::removeTicket(int ticketId) { // error checking
    ticketsRegistry.erase(ticketId);
}


const Ticket *Registry::getTicket(int ticketId) const { // error checking
    auto ptr = ticketsRegistry.find(ticketId);
    if (ptr != ticketsRegistry.end()) {
        return &ptr->second;
    }
    return nullptr;
}


void Registry::addUserTicket(const std::string &username, int id) {
    userToTicket[username].push_back(id);
}


void Registry::removeUserTicket(const std::string &username, int id) { // validation, error checking
    auto ptr = userToTicket.find(username);
    if (ptr != userToTicket.end()) {
        auto &ticketsId = ptr->second;
        ticketsId.erase(std::remove(ticketsId.begin(), ticketsId.end(), id), ticketsId.end());
        if (ticketsId.empty()) {
            userToTicket.erase(ptr);
        }
    }
}


const std::vector<int> Registry::getUserTickets(const std::string &username) const { // validation, error checking
    auto ptr = userToTicket.find(username);
    if (ptr != userToTicket.end()) {
        return ptr->second;
    }
    return {};
}









