//
// Created by Aurora Study on 15/10/24.
//

#include <stdexcept>

template <typename T> class Array {
private:
    static constexpr int MAX_SIZE = 1001;

public:
    T data[MAX_SIZE];
    int size;
    int index;

    Array() {
        this->size = 0;
        this->index = -1;
    }

    [[nodiscard]] bool isEmpty() const { return size == 0; }

    [[nodiscard]] bool isFull() const { return size == MAX_SIZE; }

    T &operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    bool insert(T &value, int index) {
        if (isFull())
            return false;
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of range");
        }

        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        size++;
        return true;
    }

    bool append(T &value) {
        if (isFull())
            return false;
        data[++index] = value;
        size++;
        return true;
    }
};
