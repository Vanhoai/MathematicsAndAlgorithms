#include <iostream>
using namespace std;

#ifndef TEMPLATE_H

#define TEMPLATE_H
template <class T> class Bag {   // Bag will be impl with array
public:
    static const int MAX = 100;

    Bag() { size = 0; }
    int sum() { return size; }

    int occurrences(const T &element) const;
    void insert(const T &element);
    void remove(const T &element);

    void operator+=(const Bag<T> &b);
    friend Bag<T> &operator+(const Bag<T> &b1, const Bag<T> &b2);
    friend ostream &operator<<(ostream &os, const Bag<T> &b);

private:
    int size;
    T data[MAX];
};

#endif