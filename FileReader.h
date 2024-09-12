#pragma once

#include "Airplane.h"
#include "Registry.h"

class FileReader {
    static Airplane processFlightRecord(const std::string &line);

public:
    static bool processFile(const std::string &path, Registry &registry);
};
