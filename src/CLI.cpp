#include <iostream>
#include <regex>

#include "CLI.h"


CLI::CLI(std::unique_ptr<CommandPerformer> commandPerformer): commandPerformer(std::move(commandPerformer)) {
}

void CLI::showMenu() {
    std::cout << "Enter command:\n"
            << "check: Check available seats for the flight\n"
            << "book: Buy a ticket for the flight\n"
            << "return: Return ticket with refund\n"
            << "view id: View the booking confirmation info\n"
            << "view user: View all booked tickets for user\n"
            << "view flight: View all booked tickets for flight\n"
            << "menu: Show menu\n"
            << "exit: Exit\n";
}

std::string CLI::getCommand() {
    std::string command;
    std::cout << "Command: ";
    std::getline(std::cin, command);
    std::transform(command.begin(), command.end(), command.begin(), ::tolower);
    return command;
}

void CLI::executeCommand(const std::string &command) const {
    if (command == "check") {
        handleCheckCommand();
    } else if (command == "book") {
        handleBookCommand();
    } else if (command == "return") {
        handleReturnCommand();
    } else if (command == "view id") {
        handleViewIdCommand();
    } else if (command == "view user") {
        handleViewUserCommand();
    } else if (command == "view flight") {
        handleViewFlightCommand();
    } else if (command == "menu") {
        showMenu();
    } else if (command == "exit") {
        std::cout << "Exiting ..." << std::endl;
    } else {
        std::cout << "Invalid command. Please, try again." << std::endl;
    }
}


void CLI::run() const {
    std::string command;
    showMenu();
    do {
        command = getCommand();
        executeCommand(command);
    } while (command != "exit");
}


void CLI::handleCheckCommand() const {
    std::string date, flightNumber;
    do {
        std::cout << "Enter date (dd.mm.yyyy): ";
        std::getline(std::cin, date);
        if (!isValidDate(date)) {
            std::cout << "Invalid date format! Please try again." << std::endl;
        }
    } while (!isValidDate(date));

    do {
        std::cout << "Enter flight number in uppercase: ";
        std::getline(std::cin, flightNumber);
        if (!isValidFlightNumber(flightNumber)) {
            std::cout << "Invalid flight number format! Please try again." << std::endl;
        }
    } while (!isValidFlightNumber(flightNumber));

    commandPerformer->check(date, flightNumber);
}

void CLI::handleBookCommand() const {
    std::string date, flightNumber, seat, username;

    do {
        std::cout << "Enter date (dd.mm.yyyy): ";
        std::getline(std::cin, date);
        if (!isValidDate(date)) {
            std::cout << "Invalid date format! Please try again." << std::endl;
        }
    } while (!isValidDate(date));

    do {
        std::cout << "Enter flight number in uppercase: ";
        std::getline(std::cin, flightNumber);
        if (!isValidFlightNumber(flightNumber)) {
            std::cout << "Invalid flight number format! Please try again." << std::endl;
        }
    } while (!isValidFlightNumber(flightNumber));

    do {
        std::cout << "Enter seat in uppercase: ";
        std::getline(std::cin, seat);
        if (!isValidSeat(seat)) {
            std::cout << "Invalid seat format! Please try again." << std::endl;
        }
    } while (!isValidSeat(seat));

    do {
        std::cout << "Enter username (up to 20 symbols without special characters): ";
        std::getline(std::cin, username);
        if (!isValidUsername(username)) {
            std::cout << "Invalid username format! Please try again." << std::endl;
        }
    } while (!isValidUsername(username));

    commandPerformer->book(date, flightNumber, seat, username);
}

void CLI::handleReturnCommand() const {
    std::string input;

    do {
        std::cout << "Enter ticket ID: ";
        std::getline(std::cin, input);
        if (!isValidId(input)) {
            std::cout << "Invalid ID! Please try again." << std::endl;
        }
    } while (!isValidId(input));

    const int ticketId = std::stoi(input);
    commandPerformer->unbook(ticketId);
}

void CLI::handleViewIdCommand() const {
    std::string input;

    do {
        std::cout << "Enter ticket ID: ";
        std::getline(std::cin, input);
        if (!isValidId(input)) {
            std::cout << "Invalid ID! Please try again." << std::endl;
        }
    } while (!isValidId(input));

    const int ticketId = std::stoi(input);
    commandPerformer->view(ticketId);
}

void CLI::handleViewUserCommand() const {
    std::string username;

    do {
        std::cout << "Enter username (up to 20 symbols without special characters): ";
        std::getline(std::cin, username);
        if (!isValidUsername(username)) {
            std::cout << "Invalid username format! Please try again." << std::endl;
        }
    } while (!isValidUsername(username));

    commandPerformer->view(username);
}

void CLI::handleViewFlightCommand() const {
    std::string date, flightNumber;

    do {
        std::cout << "Enter date (dd.mm.yyyy): ";
        std::getline(std::cin, date);
        if (!isValidDate(date)) {
            std::cout << "Invalid date format! Please try again." << std::endl;
        }
    } while (!isValidDate(date));

    do {
        std::cout << "Enter flight number in uppercase: ";
        std::getline(std::cin, flightNumber);
        if (!isValidFlightNumber(flightNumber)) {
            std::cout << "Invalid flight number format! Please try again." << std::endl;
        }
    } while (!isValidFlightNumber(flightNumber));

    commandPerformer->view(date, flightNumber);
}

bool CLI::isValidDate(const std::string &date) {
    const std::regex datePattern(R"(\d{2}\.\d{2}\.\d{4})");
    return std::regex_match(date, datePattern);
}


bool CLI::isValidFlightNumber(const std::string &flightNumber) {
    const std::regex flightPattern(R"([A-Z]{2}\d{3})");
    return std::regex_match(flightNumber, flightPattern);
}



bool CLI::isValidSeat(const std::string &seat) {
    const std::regex seatPattern(R"(\d{1,3}[A-Z])");
    return std::regex_match(seat, seatPattern);
}


bool CLI::isValidUsername(const std::string &username) {
    const std::regex usernamePattern(R"([A-Za-z0-9]{3,20})");
    return std::regex_match(username, usernamePattern);
}


bool CLI::isValidId(const std::string &idStr) {
    if (std::all_of(idStr.begin(), idStr.end(), ::isdigit)) {
        const int id = std::stoi(idStr);
        return id > 0;
    }
    return false;
}