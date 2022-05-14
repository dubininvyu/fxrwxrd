//
// Created by dubininvyu on 05.05.2022.
//


#include "Item.h"

unsigned int Item::START_ID = 0;

/*Item::Item(std::string name, float weight, float volume) : name(name), weight(weight), volume(volume) {

}*/

Item::~Item() {

}

void Item::setID(unsigned int id) {
    this->id = id;
}

unsigned int Item::getID() {
    return this->id;
}

void Item::setName(std::string name) {
    this->name = name;
}

std::string Item::getName() {
    return this->name;
}

void Item::setWeight(float weight) {
    this->weight = weight;
}
float Item::getWeight() const {
    return this->weight;
}

void Item::setVolume(float volume) {
    this->volume = volume;
}
float Item::getVolume() const {
    return this->volume;
}