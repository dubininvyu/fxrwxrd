//
// Created by dubininvyu on 03.05.2022.
//

#pragma once

class EventHandler {
private:
protected:
    EventHandler();
public:
    virtual ~EventHandler();

    virtual bool execute() = 0;
};

