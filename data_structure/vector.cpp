//
// Created by Aurora Study on 15/10/24.
//

#include <stdexcept>

template <typename T> class Vector {
private:
    T *arr;
    size_t capacity;
    size_t length;

public:
    Vector() {
        capacity = 1;
        length = 0;
        arr = new T[capacity];
    }

    ~Vector() { delete[] arr; }

    [[nodiscard]] size_t size() const { return length; }

    [[nodiscard]] bool empty() const { return length == 0; }

    T &operator[](size_t index) {
        if (index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    const T &operator[](size_t index) const {
        if (index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    void push_back(const T &value) {
        if (length == capacity) {
        }
        arr[length++] = value;
    }

    void pop_back() {
        if (length > 0) {
            --length;
        }
    }

    void insert(const T &value, size_t index) {
        if (index > length) {
            throw std::out_of_range("Index out of range");
        }
        if (length == capacity) {
            resize();
        }
        for (size_t i = length; i > index; --i) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        ++length;
    }

    void erase(size_t index) {
        if (index >= length) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < length - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --length;
    }

private:
    void resize() {
        capacity *= 2;
        T *newArr = new T[capacity];
        for (size_t i = 0; i < length; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
};
