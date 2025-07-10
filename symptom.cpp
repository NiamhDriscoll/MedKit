//
// Created by niamh_8ref0it on 7/10/2025.
//

#include "symptom.h"
#include <iostream>
#include "config.h"
#include <string>
using json = nlohmann::json;

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
    saveToFileUpdate(symptoms, "medication.json");
}




int SymptomResponseManager() {
    getSymptom();
    return 0;


}
