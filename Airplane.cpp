#include "Airplane.h" // think of getters/setters

// memory: O(n), time: O(n)
Airplane::Airplane(const std::string &date, const std::string &flightNumber, int seatsPerRow, int totalRows,
                   const std::unordered_map<int, int> &priceRange) : date(date), flightNumber(flightNumber),
                                                                     seatsPerRow(seatsPerRow), totalRows(totalRows),
                                                                     seatsAvailability(seatsPerRow * totalRows, true),
                                                                     priceRange(priceRange) {
}

// maybe it will be better to create two separate vectors booked and free

int Airplane::nextTicketId = 1;


int Airplane::getSeatPrice(const std::string &seat) const { // memory: O(1), time: O(1)
    int row = std::stoi(seat.substr(0, seat.size() - 1));
    return priceRange.at(row);
}


void Airplane::showAvailableSeatsWithPrices() const { // memory: O(1), time: O(n)
    for (int seatIndex = 0; seatIndex < seatsAvailability.size(); ++seatIndex) {
        if (seatsAvailability[seatIndex]) {
            std::string seatId = indexToSeat(seatIndex);
            int price = getSeatPrice(seatId); // repeat with row
            std::cout << seatId << " " << price << "$, ";
        }
    }
    std::cout << std::endl;
} // just for check


// show booked tickets
std::vector<int> Airplane::getBookedSeatsId() const { // memory: O(1), time: O(n)
    std::vector<int> seatsIdVector;
    for (int seatIndex = 0; seatIndex < seatsAvailability.size(); ++seatIndex) {
        if (!seatsAvailability[seatIndex]) {
            std::string seatId = indexToSeat(seatIndex);
            seatsIdVector.push_back(seatToTicket.at(seatId));
        }
    }
    return seatsIdVector;
}


int Airplane::bookSeatGetId(const std::string &seat) { // memory: O(1), time: O(1)
    int seatIndex = seatToIndex(seat);

    if (seatsAvailability[seatIndex]) {
        seatsAvailability[seatIndex] = false;
        int currentTicketId = nextTicketId++;
        seatToTicket[seat] = currentTicketId;
        return currentTicketId;
    }
    return -1;
} // then create ticket with this id


void Airplane::unbookSeat(const std::string &seat) { // memory: O(1), time: O(1)
    int seatIndex = seatToIndex(seat);

    if (!seatsAvailability[seatIndex]) {
        seatsAvailability[seatIndex] = true;
        seatToTicket.erase(seat);
    }
} // then find it in 2 other maps and delete. output its price


// helper to convert seat index to seat ID
std::string Airplane::indexToSeat(int index) const { // memory: O(1), time: O(1)
    int row = (index / seatsPerRow) + 1;
    char seatLetter = static_cast<char>('A' + (index % seatsPerRow));
    return std::to_string(row) + seatLetter;
}


// helper to convert seat ID to seat index
int Airplane::seatToIndex(const std::string &seatId) const { // memory: O(1), time: O(1)
    int row = std::stoi(seatId.substr(0, seatId.size() - 1));
    char seatLetter = seatId.back();
    return (row - 1) * seatsPerRow + (seatLetter - 'A');
}


std::ostream &operator<<(std::ostream &out, const Airplane &airplane) {
    out << "Airplane(Date: " << airplane.date << ", Flight Number: " << airplane.flightNumber << ", Seats per Row: " <<
        airplane.seatsPerRow << ", Total Rows: " <<
        airplane.totalRows << ", Seats per Row: " <<
            airplane.seatsPerRow << ")";
    return out;
}
