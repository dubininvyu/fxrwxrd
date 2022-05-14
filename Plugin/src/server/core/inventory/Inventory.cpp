//
// Created by dubininvyu on 05.05.2022.
//


#include "Inventory.h"

Inventory::Inventory(std::string name, float weight, float volume) : name(name), weight(weight), volume(volume), items(), Item() {

}

void Inventory::setName(std::string name) {
    this->name = name;
}
std::string Inventory::getName() {
    return this->name;
}

void Inventory::setWeight(float weight) {
    this->weight = weight;
}
float Inventory::getWeight() {
    return this->weight;
}

void Inventory::setVolume(float volume) {
    this->volume = volume;
}
float Inventory::getVolume() {
    return this->volume;
}

std::vector<Item*> Inventory::getItems() {
    return this->items;
}