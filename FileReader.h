#pragma once
#include <iostream>

#include "Airplane.h"
#include "Registry.h"

class FileReader {
    std::string filePath;

    static Airplane parseFlightRecord(const std::string &line);
public:
    explicit FileReader(const std::string &filePath): filePath(filePath) {}

    void parseFile(Registry &registry) const;
};
