//
// Created by Aurora Study on 16/10/24.
//

#include "iostream"
using namespace std;

template <class T> struct NodeQueue {
    T value;
    NodeQueue *next;
};

template <typename T> class Queue {
private:
    NodeQueue<T> *head;
    NodeQueue<T> *tail;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    ~Queue() {
        NodeQueue<T> *current = head;
        while (current != nullptr) {
            const NodeQueue<T> *tmp = current;
            current = current->next;
            delete tmp;
        }
    }

    NodeQueue<T> *makeNode(const T value) {
        auto *node = new NodeQueue<T>;
        node->value = value;
        node->next = nullptr;
        return node;
    }

    [[nodiscard]] bool isEmpty() const { return head == nullptr; }

    void push(const T &value) {
        if (isEmpty()) {
            head = makeNode(value);
            tail = head;
            return;
        }

        tail->next = makeNode(value);
        tail = tail->next;
    }

    T front() { return head->value; }

    bool pop() {
        if (isEmpty())
            return false;

        const NodeQueue<T> *tmp = head;
        head = head->next;
        delete tmp;
        return true;
    }

    T headQueue() const { return head->value; }

    T tailQueue() const { return tail->value; }

    void printQueue() const {
        cout << "Head: " << headQueue() << ", Tail: " << tailQueue() << endl;
        NodeQueue<T> *current = head;
        while (current != nullptr) {
            cout << current->value;
            current = current->next;
            if (current != nullptr) {
                cout << " -> ";
            }
        }

        cout << endl;
    }
};

int main_queue() {
    Queue<int> *queue = new Queue<int>();
    queue->push(1);
    queue->push(2);
    queue->push(3);
    queue->push(4);
    queue->push(5);

    queue->printQueue();
    cout << "Front queue: " << queue->front() << endl;
    queue->pop();
    cout << "Front queue: " << queue->front() << endl;

    delete queue;
    return 0;
}
