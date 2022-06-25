//
// Created by dubininvyu on 05.05.2022.
//


#include "Inventory.h"

Inventory::Inventory(const string& name, const float maxWeight, const float weight, const float length, const float width, const float height) :
    maxWeight(maxWeight)/*, Item(name, weight, length, width, height)*/ {

}

float Inventory::getMaxWeight() const {
    return maxWeight;
}