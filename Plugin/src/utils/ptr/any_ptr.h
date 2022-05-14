//
// Created by dubininvyu on 01.05.2022.
//


#pragma once

#include "ptr_t.h"

class any_ptr {
private:
    void* ptr;
protected:
public:
    any_ptr();

    template <typename T>
    any_ptr(const T& ptr);

    template <typename T>
    operator T();
};

