#include <iostream>
#include <json.hpp>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <string>
#include <chrono>
#include <thread>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <vector>
#include <algorithm>

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

    STARTUPINFO si;
        PROCESS_INFORMATION pi;
        const char* cmd = "python main.py";
        CreateProcess(nullptr, static_cast<LPSTR>(const_cast<char*>(cmd)), nullptr, nullptr, FALSE, 0, nullptr, nullptr, &si, &pi);
    std::cout << "Medication reminder started!" << std::endl;
    while (true) {
        std::ifstream file("bool.txt");
        if (!file.is_open()) {
            std::cout << "Error opening file" << std::endl;
            continue;
        }
        std::string data;
        std::getline(file, data);
        file.close();
        data = "True";
        if (data == "True") {
            std::ifstream med("med.txt");
            std::string medData;
            std::getline(med, medData);
            med.close();
            MessageBoxW(nullptr, (L"Take your medication: " + std::wstring(medData.begin(), medData.end())).c_str(), L"Reminder", MB_OK);
            std::ofstream boolFile("bool.txt");
            boolFile << "False";
            boolFile.close();
            std::this_thread::sleep_for(std::chrono::seconds(60));

        }
    }
    }
    else {
        return 0;

    }

}