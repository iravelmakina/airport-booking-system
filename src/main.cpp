#include <iostream>

#include "Registry.h"
#include "FileReader.h"
#include "CommandPerformer.h"
#include "CLI.h"

int main() {
    std::unique_ptr<Registry> registry = std::make_unique<Registry>(); // used make_unique because it is safer
    if (!FileReader::processFile("../Config.txt", *registry)) {
        return 1;
    }

    std::unique_ptr<CommandPerformer> commandPerformer = std::make_unique<CommandPerformer>(std::move(registry)); // used make_unique because it is safer
    std::cout << "Welcome to airport booking system!" << std::endl;
    const CLI cli(std::move(commandPerformer));
    cli.run();
    return 0;
}
