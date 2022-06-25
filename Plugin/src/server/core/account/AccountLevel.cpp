//
// Created by dubininvyu on 18.06.2022.
//

#include "AccountLevel.h"
#include "Account.h"
#include "Player.h"
#include "Person.h"
#include "natives.h"

namespace native = api_server::native;

AccountLevel::AccountLevel(Account* account) : account(account) {

}

AccountLevel::~AccountLevel() {

}

void AccountLevel::increase() {
    setLevel(level + 1);
}

void AccountLevel::decrease() {
    setLevel(level - 1);
}

void AccountLevel::setLevel(const level_t level) {
    this->level = level;
    account->getPlayer()->getScore()->setScore(level);
}

void AccountLevel::syncLevel() {
    this->level = account->getPlayer()->getScore()->getScore();
}

level_t AccountLevel::getLevel() const {
    return this->level;
}

AccountLevel::operator level_t() const {
    return getLevel();
}