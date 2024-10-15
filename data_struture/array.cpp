//
// Created by Aurora Study on 15/10/24.
//

#include "array.h"
using namespace std;

template <class T>
class Array {
public:
    static constexpr int MAX_SIZE = 1001;
    Array() {
        this->last = -1;
        this->current = -1;
    }

    bool isEmpty() {
        return this->last < 0;
    }

private:
    T data[MAX_SIZE];
    int last = -1;
    int current = -1;
};