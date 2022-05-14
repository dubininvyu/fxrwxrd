//
// Created by dubininvyu on 01.05.2022.
//


#pragma once

template <typename T>
class ptr_t {
private:
    T* data;
protected:
public:
    ptr_t(T* data);
    ptr_t(T& data);

    operator T*();
    operator T&();

    bool operator==(const T* data);
    bool operator==(const T& data);
    bool operator==(const ptr_t<T>& data);
};

