//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

#include "Entity.h"

#include <string>

using namespace std;

class LawSubject : public virtual Entity {
private:
protected:
public:
    LawSubject();
    virtual ~LawSubject();
};