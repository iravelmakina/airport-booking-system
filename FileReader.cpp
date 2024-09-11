#include "FileReader.h"

#include <fstream>
#include <sstream>


void FileReader::parseFile(Registry &registry) const {
    std::ifstream configFile(filePath);
    if (!configFile.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return;
    }

    std::string line;
    int numberOfRecords;

    while (std::getline(configFile, line)) {
        std::istringstream lineStream(line);

        if (lineStream >> numberOfRecords) {
            for (int i = 0; i < numberOfRecords; ++i) {
                std::getline(configFile, line);
                Airplane airplane = parseFlightRecord(line);
                registry.addAirplane(airplane.date, airplane.flightNumber, airplane);
            }
        } else {
            std::cerr << "Error: Failed to read flight record." << std::endl;
        }
    }
    configFile.close();
}

Airplane FileReader::parseFlightRecord(const std::string &line) {
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

    return Airplane(date, flightNumber, seatsPerRow, maxRow, priceRange);
}