//
// Created by dubininvyu on 14.05.2022.
//


#pragma once

class Person;

class PersonCamera {
public:
    enum SpectatingMode {
        MODE_OFF,
        MODE_ON
    };
private:
protected:
    Person* person;
    SpectatingMode mode;
public:
    PersonCamera(Person* person);

    bool isPlayerSpectating() const;
    bool setSpectatingMode(SpectatingMode mode);
};

