#include <iostream>
#include <json.hpp>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <string>
#include <chrono>
#include <thread>

#include <algorithm>

#include "config.h"
#include "symptom.h"
using json = nlohmann::json;

void reminderSound() {
    PlaySound(TEXT("SystemExclamation"), nullptr, SND_ALIAS | SND_ASYNC);


}


int main() {

    std::cout << "MedKit 0.1 built by Niamh Driscoll" << std::endl;
    std::cout << "Welcome to MedKit! Would you like to set new medications or run as usual?" << std::endl;
    std::cout << "1. Configure program" << std::endl;
    std::cout << "2. Run as usual" << std::endl;
    std::cout << "3. Open Symptom Response Manager" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::string input;
    std::getline(std::cin, input);
    if (input == "1") {
        config();
    }
    if (input == "2") {

    STARTUPINFO si = {sizeof(si)};
        PROCESS_INFORMATION pi;
        ZeroMemory(&si, sizeof(si));
        ZeroMemory(&pi, sizeof(pi));
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

        if (data == "True") {
            std::ifstream med("med.txt");
            std::string medData;
            std::getline(med, medData);
            med.close();
            reminderSound();
            MessageBoxW(nullptr, (L"Take your medication: " + std::wstring(medData.begin(), medData.end())).c_str(), L"Reminder", MB_OK);
            std::ofstream boolFile("bool.txt");
            boolFile << "False";
            boolFile.close();
            std::this_thread::sleep_for(std::chrono::seconds(60));

        }
    }
    }
    if (input == "3") {
        SymptomResponseManager();
    }
    if (input == "4") {

        return 0;
    }
    else {
        return 1;

    }

}

//int main() {
//    while (true) {
//        main_function();
//    }

//}