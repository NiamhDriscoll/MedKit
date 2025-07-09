#include <iostream>
#include <fstream>
#include <json.hpp>

using json = nlohmann::json;
void saveToFile(const json& j, const std::string& filename) {
    std::ofstream file(filename);
    file << j.dump(2);
}


void setMedicationTime() {
    std::string monInputTime;
    std::string tueInputTime;
    std::string wedInputTime;
    std::string thuInputTime;
    std::string friInputTime;
    std::string satInputTime;
    std::string sunInputTime;
    std::cout << "Enter the medication time on Monday: ";
    std::getline(std::cin, monInputTime);
    std::cout << "Enter the medication time on Tuesday: ";
    std::getline(std::cin, tueInputTime);
    std::cout << "Enter the medication time on Wednesday: ";
    std::getline(std::cin, wedInputTime);
    std::cout << "Enter the medication time on Thursday: ";
    std::getline(std::cin, thuInputTime);
    std::cout << "Enter the medication time on Friday: ";
    std::getline(std::cin, friInputTime);
    std::cout << "Enter the medication time on Saturday: ";
    std::getline(std::cin, satInputTime);
    std::cout << "Enter the medication time on Sunday: ";
    std::getline(std::cin, sunInputTime);
    std::cout << "Medication set successfully!" << std::endl;
    json medication ={
        {"MonTime", monInputTime},
        {"TueTime", tueInputTime},
        {"WedTime", wedInputTime},
        {"ThuTime", thuInputTime},
        {"FriTime", friInputTime},
        {"SatTime", satInputTime},
        {"SunTime", sunInputTime}
    };
    saveToFile(medication, "time.json");
}
void setMedication() {
    std::string monInput;
    std::string tueInput;
    std::string wedInput;
    std::string thuInput;
    std::string friInput;
    std::string satInput;
    std::string sunInput;
    std::cout << "Enter the medication you take on Monday: ";
    std::getline(std::cin, monInput);
    std::cout << "Enter the medication you take on Tuesday: ";
    std::getline(std::cin, tueInput);
    std::cout << "Enter the medication you take on Wednesday: ";
    std::getline(std::cin, wedInput);
    std::cout << "Enter the medication you take on Thursday: ";
    std::getline(std::cin, thuInput);
    std::cout << "Enter the medication you take on Friday: ";
    std::getline(std::cin, friInput);
    std::cout << "Enter the medication you take on Saturday: ";
    std::getline(std::cin, satInput);
    std::cout << "Enter the medication you take on Sunday: ";
    std::getline(std::cin, sunInput);
    std::cout << "Medication set successfully!" << std::endl;
    json medication ={
        {"Mon", monInput},
        {"Tue", tueInput},
        {"Wed", wedInput},
        {"Thu", thuInput},
        {"Fri", friInput},
        {"Sat", satInput},
        {"Sun", sunInput}
    };

    saveToFile(medication, "medication.json");
}
int config() {
    std::cout << "Welcome to the configuration of MedKit" << std::endl;
    std::cout << "Please select what you want to change 1: Change medications 2: Change times 3: End program: ";
    std::string input;
    std::getline(std::cin, input);
    if (input == "1") {
        setMedication();
        return 0;
    }
    if (input == "2") {
        setMedicationTime();
        return 0;
    }
    if (input == "3") {
        return 0;
    }
    return 1;
}
