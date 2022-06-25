//
// Created by dubininvyu on 05.05.2022.
//

#pragma once

#include "Item.h"

#include <string>
#include <vector>

using namespace std;

class Inventory : public virtual Item, public vector<Item*> {
private:
protected:
    float maxWeight;
public:
    Inventory(const string& name, const float maxWeight, const float weight, const float length, const float width, const float height);

    float getMaxWeight() const;
};