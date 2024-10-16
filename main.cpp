#include <iostream>
#include <string>
using namespace std;

struct Node {
    int value;
    Node* next;
};

Node* makeNode(const int value) {
    const auto node = new Node;
    node->value = value;
    node->next = nullptr;
    return node;
}

class LinkedList {
    Node* head;
    Node* tail;
    public:
        LinkedList() {
            head = nullptr;
            tail = nullptr;
        }

        [[nodiscard]] bool isEmpty() const {
            return head == nullptr;
        }

        void append(const int value) {
            if (isEmpty()) {
                head = makeNode(value);
                tail = head;
            }

            tail->next = makeNode(value);
            tail = tail->next;
        }

        void insert(const int value, const int index) {
            if (index == 0) {
                head = makeNode(value);
                tail = head;
                return;
            }

            if (index == 1) {
                head->next = makeNode(value);
                tail = head->next;
                return;
            }

            auto current = head;
            for (int i = 1; i < index; i++) {
                current = current->next;
            }

            current->next = makeNode(value);
            tail = current->next;
        }

        void remove(const int index) {
            if (index == 0) {
                head = head->next;
                return;
            }

            auto current = head;
            for (int i = 1; i < index; i++) {
                current = current->next;
            }

            current->next = current->next->next;
        }

        void print() const {
            auto current = head;

            while (current != nullptr) {
                cout << current->value;
                current = current->next;

                if (current != nullptr) {
                    cout << " -> ";
                }
            }
        }
};

int main() {
    const auto list = new LinkedList();

    list->append(1);
    list->append(2);
    list->append(3);
    list->append(4);
    list->append(5);

    list->print();

    delete list;
    return 0;
}
