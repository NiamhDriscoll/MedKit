//
// Created by niamh_8ref0it on 7/3/2025.
//

#ifndef UNTITLED_CONFIG_H
#define UNTITLED_CONFIG_H

#include <string>
#include <json.hpp>

using json = nlohmann::json;
void saveToFile(const json& j, const std::string& filename);
void setMedicationTime();
void setMedication();
int config();


#endif //UNTITLED_CONFIG_H
