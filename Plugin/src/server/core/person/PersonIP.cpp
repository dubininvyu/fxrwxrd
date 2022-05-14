//
// Created by dubininvyu on 11.05.2022.
//

#include "PersonIP.h"

#include "Person.h"
#include "natives.h"

PersonIP::PersonIP(const string &ip) : PersonIP(nullptr, ip) {

}

PersonIP::PersonIP(Person* person, const string& ip) : person(person), ip(ip) {

}

void PersonIP::setIP(const string& ip) {
    this->ip = ip;
}

string PersonIP::getIP() const {
    return this->ip;
}

void PersonIP::syncIP() {
    char ip[MAX_LENGTH];
    api_server::native::GetPlayerIp(person->getID(), ip, MAX_LENGTH);
    this->ip = ip;
}