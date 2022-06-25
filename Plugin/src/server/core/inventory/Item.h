//
// Created by dubininvyu on 05.05.2022.
//

#pragma once

#include "Entity.h"
#include "ItemType.h"

#include <string>

using namespace std;

typedef size_t itemID_t;

class Item : public virtual Entity {
public:
private:
protected:
    itemID_t id;
    string name;

    ItemType type;

    float weight;
    float length;
    float width;
    float height;

    float volume;

    // =============== setters & getters
    void setID(const itemID_t id);
    itemID_t getID() const;
public:
    // =============== constructors & destructors
    //Item(const ItemType type, const string& name, const float weight, const float length, const float width, const float height);
    virtual ~Item();

    // =============== methods
    virtual void compute();

    // =============== setters & getters
    void setName(const string& name);
    string getName() const;

    void setWeight(const float weight);
    float getWeight() const;

    void setVolume(const float volume);
    float getVolume() const;

    void setLength(const float length);
    float getLength() const;

    void setWidth(const float width);
    float getWidth() const;

    void setHeight(const float height);
    float getHeight() const;
};