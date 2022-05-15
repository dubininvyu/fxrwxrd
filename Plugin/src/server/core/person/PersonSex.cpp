//
// Created by dubininvyu on 02.05.2022.
//

#include "PersonSex.h"

#include "Person.h"

#include <string>

using namespace std;

PersonSex::PersonSex(Person* person) : person(person) {

}

void PersonSex::setSex(const Sex sex) {
    this->sex = sex;
}

PersonSex::Sex PersonSex::getSex() const {
    return this->sex;
}

bool PersonSex::isMale() const {
    return sex == SEX_MALE;
}

bool PersonSex::isFemale() const {
    return sex == SEX_FEMALE;
}