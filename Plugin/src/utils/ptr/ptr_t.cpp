//
// Created by dubininvyu on 01.05.2022.
//

#include "ptr_t.h"

template <typename T>
ptr_t<T>::ptr_t(T* data) : data(&data) {

}

template <typename T>
ptr_t<T>::ptr_t(T& data) : ptr_t(&data) {

}

template <typename T>
ptr_t<T>::operator T*() {
    return data;
}

template <typename T>
ptr_t<T>::operator T&() {
    return *data;
}

template <typename T>
bool ptr_t<T>::operator==(const T* data) {
    return (this->data == data);
}

template <typename T>
bool ptr_t<T>::operator==(const T& data) {
    return operator==(&data);
}

template <typename T>
bool ptr_t<T>::operator==(const ptr_t<T>& data) {
    return operator==(&data.data);
}