#include <iostream>
#include <fstream>
#include <sstream>

#include "FileReader.h"


bool FileReader::processFile(const std::string &path, Registry &registry) {
    // memory: O(n * m), time: O(n * m)
    std::ifstream configFile(path);
    if (!configFile.is_open()) {
        std::cerr << "Error: Failed to open the file." << std::endl;
        return false;
    }

    std::string line;
    int numberOfRecords;

    while (std::getline(configFile, line)) {
        std::istringstream lineStream(line);

        if (lineStream >> numberOfRecords) {
            for (int i = 0; i < numberOfRecords; ++i) {
                std::getline(configFile, line);
                Airplane airplane = processFlightRecord(line);
                registry.addAirplane(airplane.date, airplane.flightNumber, airplane);
            }
        } else {
            std::cerr << "Error: Failed to read flight record." << std::endl;
            return false;
        }
    }
    configFile.close();
    return true;
}

Airplane FileReader::processFlightRecord(const std::string &line) {
    // memory: O(m), time: O(m)
    std::istringstream lineStream(line);

    std::string date, flightNumber;
    int seatsPerRow;
    lineStream >> date >> flightNumber >> seatsPerRow;

    std::unordered_map<int, int> priceRange;
    int rowStart, rowEnd, price;
    char dollarSign;

    int maxRow = 0;
    while (lineStream >> rowStart) {
        lineStream.ignore(1, '-');
        lineStream >> rowEnd >> price >> dollarSign;
        for (int row = rowStart; row <= rowEnd; ++row) {
            priceRange[row] = price;
        }
        if (rowEnd > maxRow) {
            maxRow = rowEnd;
        }
    }

    return {date, flightNumber, seatsPerRow, maxRow, priceRange};
}
