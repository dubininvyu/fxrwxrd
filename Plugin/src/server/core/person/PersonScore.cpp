//
// Created by dubininvyu on 02.05.2022.
//

#include "PersonScore.h"

#include "Person.h"
#include "natives.h"

namespace native = api_server::native;

PersonScore::PersonScore(Person* person, const score_t score) : person(person), score(score) {

}

void PersonScore::increase() {
    setScore(score + 1);
}

void PersonScore::decrease() {
    setScore(score - 1);
}

void PersonScore::setScore(const score_t score) {
    this->score = score;
    native::SetPlayerScore(person->getID(), this->score);
}

void PersonScore::syncScore() {
    score = native::GetPlayerScore(person->getID());
}

score_t PersonScore::getScore() const {
    return score;
}