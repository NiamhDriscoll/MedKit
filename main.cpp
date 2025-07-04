#include <iostream>
#include <json.hpp>
#include <fstream>
#include "config.h"
using json = nlohmann::json;




int main() {
    std::cout << "MedKit 0.1 built by Niamh Driscoll" << std::endl;
    std::cout << "Welcome to MedKit! Would you like to set new medications or run as usual?" << std::endl;
    std::cout << "1. Configure program 2. Run as usual: ";
    std::string input;
    std::getline(std::cin, input);
    if (input == "1") {
        config();
    }
    if (input == "2") {
        return 0;
    }
    else {
        return 0;

    }

}

