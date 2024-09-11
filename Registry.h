#pragma once
#include <iostream>
#include <unordered_map>
#include <unordered_set>

#include "Airplane.h"


class Registry {
    std::unordered_map<std::string, Airplane> airflightsRegistry;
    std::unordered_map<int, Ticket> ticketsRegistry;
    std::unordered_map<std::string, std::unordered_set<int>> userToTicket;

public:
    void addAirplane(const std::string &date, const std::string &flightNumber, const Airplane &airplane);

    Airplane *getAirplane(const std::string &date, const std::string &flightNumber);

    void addTicket(int ticketId, const Ticket &ticket); // create ticket here

    void removeTicket(int ticketId);

    const Ticket *getTicket(int ticketId) const;

    void addUserTicket(const std::string &username, int id);

    void removeUserTicket(const std::string &username, int id);

    const std::unordered_set<int> getUserTickets(const std::string &username) const;
};
