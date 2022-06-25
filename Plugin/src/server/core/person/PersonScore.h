//
// Created by dubininvyu on 02.05.2022.
//


#pragma once

#include <boost/mpl/size_t.hpp>

class Person;

typedef size_t score_t;

class PersonScore {
public:
private:
protected:
    Person* person;
    score_t score;
public:
    PersonScore(Person* person, const score_t score = 0);

    void increase();
    void decrease();

    void setScore(const score_t score);
    void syncScore();
    score_t getScore() const;
};

