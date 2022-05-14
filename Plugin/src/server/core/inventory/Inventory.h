//
// Created by dubininvyu on 05.05.2022.
//

#pragma once

#include <string>
#include <vector>
#include "Item.h"

class Inventory : Item {
private:
protected:
    std::string name;

    float weight;
    float volume;

    std::vector<Item*> items = std::vector<Item*>();
public:
    Inventory(std::string name, float weight, float volume);

    void setName(std::string name);
    std::string getName();

    void setWeight(float weight);
    float getWeight();

    void setVolume(float volume);
    float getVolume();

    std::vector<Item*> getItems();
};