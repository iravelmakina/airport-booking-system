#pragma once
#include <iostream>
#include <unordered_map>

#include "Airplane.h"


class Registry {
private:
    std::unordered_map<std::pair<std::string, std::string>, Airplane> airflightsRegistry;
    std::unordered_map<int, Ticket> ticketsRegistry;
    std::unordered_map<std::string, std::vector<int>> userToTicket;

public:
    void addAirplane(const std::string &date, const std::string &flightNumber, const Airplane &airplane);

    const Airplane *getAirplane(const std::string &date, const std::string &flightNumber) const;

    void addTicket(int ticketId, const Ticket &ticket); // create ticket here

    void removeTicket(int ticketId);

    const Ticket *getTicket(int ticketId) const;

    void addUserTicket(const std::string &username, int id);

    void removeUserTicket(const std::string &username);

    const std::vector<int> getUserTickets(const std::string &username) const;
};
