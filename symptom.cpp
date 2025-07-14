//
// Created by niamh_8ref0it on 7/10/2025.
//

#include "symptom.h"
#include <iostream>
#include "config.h"
#include <string>
#include <fstream>
#include <json.hpp>
#include <algorithm>
#include <chrono>
#include <thread>
#include <vector>
#include <map>
using json = nlohmann::json;
void saveToFileUpdate(const json& j, const std::string& filename) {
    json oldFile;
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        try {
            inFile >> oldFile;
        }
        catch (std::exception& e) {
            std::cout << "Error reading file: " << e.what() << std::endl;
            return;
        }
        inFile.close();
    }
    else {
        std::cout << "Error opening file" << std::endl;
        return;
    }
    oldFile.update(j);
    std::ofstream outFile(filename);

    outFile << oldFile.dump(2);
    outFile.close();
}
void getSymptom() {
    std::string symptomAdd;
    std::string treatmentAdd;

    std::cout << "Enter the symptom you want to add to the Symptom Response Manager: ";
    std::getline(std::cin, symptomAdd);
    std::cout << "Enter what treatment you want for that symptom: ";
    std::getline(std::cin, treatmentAdd);
    json symptoms ={
        {symptomAdd, treatmentAdd}
    };
    saveToFileUpdate(symptoms, "symptoms.json");
}

void helper() {

}


int SymptomResponseManager() {
    std::cout << "Symptom Response Manager" << std::endl;
    std::cout << "1. Add a new symptom to the Symptom Response Manager" << std::endl;
    std::cout << "2. Remove a symptom from the Symptom Response Manager" << std::endl;
    std::cout << "3. View the Symptom Response Manager" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::string input;
    std::getline(std::cin, input);
    if (input == "1") {
getSymptom();}
    if (input == "2") {

}
    if (input == "3") {

}
    return 0;


}
