//
// Created by dubininvyu on 01.05.2022.
//


#pragma once

#include "Entity.h"

class VehicleComponent : Entity {
public:
    enum ComponentType {
        SPOILER = 0,
        HOOD,
        ROOF,
        SIDE_SKIRT,
        LAMPS,
        NITRO,
        EXHAUST,
        WHEELS,
        STEREO,
        HYDRAULICS,
        BUMPER_FRONT,
        BUMPER_REAR,
        VENT_RIGHT,
        VENT_LEFT
    };
};

