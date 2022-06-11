//
// Created by dubininvyu on 10.05.2022.
//

#include "PersonSpawn.h"

#include "natives.h"
#include "Person.h"

PersonSpawn::PersonSpawn(Person* person) : person(person), skin(), team(), position() {

}

bool PersonSpawn::spawn() {
    return api_server::native::SpawnPlayer(person->getID());
}

bool PersonSpawn::setSpawnInfo() {
    unsigned int id = person->getID();
    unsigned int teamID = team.getTeam();
    unsigned int skinID = skin.getSkin();

    vec4d& pos = position.getPosition();

    return api_server::native::SetSpawnInfo(id, teamID, skinID, pos, 0, 0, 0, 0, 0, 0);
}

PersonSkin& PersonSpawn::getSkin() {
    return skin;
}

PersonTeam& PersonSpawn::getTeam() {
    return team;
}

PersonPosition& PersonSpawn::getPosition() {
    return position;
}