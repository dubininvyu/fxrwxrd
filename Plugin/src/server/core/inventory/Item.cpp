//
// Created by dubininvyu on 05.05.2022.
//


#include "Item.h"

using namespace std;

/*Item::Item(const ItemType type, const string& name, const float weight, const float length, const float width, const float height) :
    Entity(), type(type), name(name), weight(weight), length(length), width(width), height(height) {

    compute();
}*/

Item::~Item() {

}

/* params */
void Item::compute() {
    volume = length * width * height;
}

/* methods */
void Item::setID(const itemID_t uid) {
    this->id = uid;
}

itemID_t Item::getID() const {
    return id;
}

void Item::setName(const string& name) {
    this->name = name;
}

string Item::getName() const {
    return this->name;
}

void Item::setWeight(const float weight) {
    this->weight = weight;
}

float Item::getWeight() const {
    return this->weight;
}

void Item::setVolume(const float volume) {
    this->volume = volume;
}

float Item::getVolume() const {
    return this->volume;
}

void Item::setLength(const float length) {
    this->length = length;
}

float Item::getLength() const {
    return length;
}

void Item::setWidth(const float width) {
    this->width = width;
}

float Item::getWidth() const {
    return width;
}

void Item::setHeight(const float height) {
    this->height = height;
}

float Item::getHeight() const {
    return height;
}