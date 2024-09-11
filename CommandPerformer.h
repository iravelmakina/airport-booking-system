#pragma once

#include "Registry.h"


class CommandPerformer {
    Registry &registry;

    Airplane *getAirplaneOrError(const std::string &date, const std::string &flightNumber) const;

public:
    explicit CommandPerformer(Registry &registry);

    void check(const std::string &date, const std::string &flightNumber) const;

    void book(const std::string &date, const std::string &flighNumber, const std::string &seat, const std::string &username) const;

    void unbook(int id) const;

    void view(int id) const;

    void view(const std::string &username) const;

    void view(const std::string &date, const std::string &flightNumber) const;
};
