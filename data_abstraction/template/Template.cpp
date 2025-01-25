#include "Template.h"
#include <assert.h>
#include <iostream>
using namespace std;

template <class T> int Bag<T>::occurrences(const T &item) const {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (data[i] == item) {
            count++;
        }
    }
}

template <class T> void Bag<T>::insert(const T &element) {
    assert(sum() < MAX);
    data[size++] = element;
}

template <class T> void Bag<T>::remove(const T &element) {
    int i;
    for (i = 0; (i < size) && (data[i] != element); i++)
        ;

    if (i == size)
        return;

    data[i] = data[--size];
}

template <class T> void Bag<T>::operator+=(const Bag<T> &b) {
    assert(sum() + b.sum() < MAX);

    for (int i = 0; i < b.size; i++) {
        data[size++] = b.data[i];
    }
}

template <class T> Bag<T> &operator+(const Bag<T> &b1, const Bag<T> &b2) {
    assert(b1.sum() + b2.sum() < Bag<T>::MAX);

    Bag<T> B;
    B += b1;
    B += b2;

    return B;
}

template <class T> ostream &operator<<(ostream &os, const Bag<T> &b) {
    for (int i = 0; i < b.size; i++) {
        os << b.data[i] << " ";
    }
    return os;
}