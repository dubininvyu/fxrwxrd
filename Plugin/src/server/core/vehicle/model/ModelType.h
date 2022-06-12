//
// Created by dubininvyu on 12.06.2022.
//


#pragma once

class ModelType {
public:
    enum Type {
        TYPE_CAR = 0,
        TYPE_BOAT,
        TYPE_HELICOPTER,
        TYPE_AIRPLANE,
        TYPE_BICYCLE,
        TYPE_TRAIN,
        TYPE_TRAILER,
        TYPE_BIKE,
        TYPE_REMOTE,
        TYPE_UNKNOWN,

        COUNT
    };
private:
protected:
public:
    ModelType();
    ~ModelType();
};

