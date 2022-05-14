//
// Created by dubininvyu on 10.05.2022.
//


#pragma once

class Person;

class PersonTeam {
public:
    enum Team {
        TEAM_ONE = 0,
        TEAM_TWO,

        TEAM_NO = 255
    };
private:
protected:
    Person* person;
    Team team;
public:
    PersonTeam(Team team = TEAM_NO);
    PersonTeam(Person* person, Team team = TEAM_NO);

    void setTeam(Team team);
    Team getTeam() const;
};

