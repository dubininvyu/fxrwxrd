//
// Created by dubininvyu on 22.06.2022.
//

#include "CreateVehicleCommand.h"
#include "Vehicle.h"
#include "Player.h"
#include "geometry.h"

using namespace geometry;

CreateVehicleCommand::CreateVehicleCommand(Player* player, const string& params) : AdminCommand(player, params) {

}

bool CreateVehicleCommand::execute() {
    player->getPosition()->syncPosition(); // Sync position (get current one)
    vec4d position = player->getPosition()->getPosition();

    colorID_t colors[2] = {1, 79};
    //Vehicle::create(427, position, colors);

    player->sendMessage("Машинка успешно создана");

    return false;
}