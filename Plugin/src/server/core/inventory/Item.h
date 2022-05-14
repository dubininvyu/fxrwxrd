//
// Created by dubininvyu on 05.05.2022.
//

#pragma once

#include "Entity.h"
#include <string>

class Item : Entity {
public:
    static unsigned int START_ID;
private:
protected:
    virtual ~Item();

    unsigned int id;
    std::string name;

    float weight;
    float volume;
public:
    //Item(std::string name, float weight = 0, float volume = 0);

    virtual void calculate() = 0;

    virtual float MIN_WEIGHT() const = 0;
    virtual float MIN_VOLUME() const = 0;
    virtual float MIN_VOLUME_LENGTH() const = 0;
    virtual float MIN_VOLUME_WIDTH() const = 0;
    virtual float MIN_VOLUME_HEIGHT() const = 0;

    void setID(unsigned int id);
    unsigned int getID();

    void setName(std::string name);
    std::string getName();

    void setWeight(float weight);
    float getWeight() const;

    void setVolume(float volume);
    float getVolume() const;
};