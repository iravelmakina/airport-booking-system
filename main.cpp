#include <iostream>

#include "Registry.h"
#include "FileReader.h"
#include "CommandPerformer.h"
#include "CLI.h"

int main() {
    std::unique_ptr<Registry> registry(new Registry());
    if (!FileReader::processFile("Config.txt", *registry)) {
        return 1;
    }

    std::unique_ptr<CommandPerformer> commandPerformer(new CommandPerformer(std::move(registry)));
    std::cout << "Welcome to airport booking system!" << std::endl;
    const CLI cli(std::move(commandPerformer));
    cli.run();
    return 0;
}
