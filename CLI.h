#pragma once

#include "CLI.h"
#include "CommandPerformer.h"


class CLI {
    std::unique_ptr<CommandPerformer> commandPerformer;

    static void showMenu();

    static std::string getCommand();

    void executeCommand(const std::string &command) const;

    void handleCheckCommand() const;

    void handleBookCommand() const;

    void handleReturnCommand() const;

    void handleViewIdCommand() const;

    void handleViewUserCommand() const;

    void handleViewFlightCommand() const;

    static bool isValidDate(const std::string &date);

    static bool isValidFlightNumber(const std::string &flightNumber);

    static bool isValidSeat(const std::string &seat);

    static bool isValidUsername(const std::string &username);

    static bool isValidId(const std::string &idStr);

public:
    explicit CLI(std::unique_ptr<CommandPerformer> commandPerformer);

    void run() const;
};
