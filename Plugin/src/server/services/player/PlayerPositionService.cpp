//
// Created by dubininvyu on 07.05.2022.
//

#include "PlayerPositionService.h"

#include "repositories.h"

PlayerPositionService::PlayerPositionService(Player* player) :
    PlayerService(player), positionRepository(player) {
}

PlayerPositionService::~PlayerPositionService() {

}

void PlayerPositionService::savePosition() {
    player->getPosition()->syncPosition(); // synchronize player position
    positionRepository.update();
}
