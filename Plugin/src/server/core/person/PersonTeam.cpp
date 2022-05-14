//
// Created by dubininvyu on 10.05.2022.
//

#include "PersonTeam.h"

PersonTeam::PersonTeam(Team team) : PersonTeam(nullptr, team) {

}

PersonTeam::PersonTeam(Person* person, Team team) : person(person), team(team) {

}

void PersonTeam::setTeam(Team team) {
    this->team = team;
}

PersonTeam::Team PersonTeam::getTeam() const {
    return this->team;
}