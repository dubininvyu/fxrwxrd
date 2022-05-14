//
// Created by dubininvyu on 01.05.2022.
//

#include "any_ptr.h"

any_ptr::any_ptr() {

}

template <typename T>
any_ptr::any_ptr(const T& ptr) : ptr((void*) ptr) {

}

template <typename T>
any_ptr::operator T() {
    return (T) ptr;
}