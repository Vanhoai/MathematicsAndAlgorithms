#include "iostream"
using namespace std;

template<class T>
struct Node {
    T value;
    Node* next;
};

template <typename T>
class Stack {
    Node<T> *head;
    int size;
    public:
        Stack() {
            head = nullptr;
            size = 0;
        }

        ~Stack() {
            Node<T> *current = head;
            while (current != nullptr) {
                const Node<T> *tmp = current;
                current = current->next;
                delete tmp;
            }

            head = nullptr;
            size = 0;
        }

        Node<T>* makeNode(const T value) {
            Node<T>* node = new Node<T>;
            node->value = value;
            node->next = nullptr;
            return node;
        }

        [[nodiscard]] bool isEmpty() const {
            return head == nullptr;
        }

        void push(const T &value) {
            if (isEmpty()) {
                head = makeNode(value);
                return;
            }

            Node<T> *newNode = makeNode(value);
            newNode->next = head;
            head = newNode;
        }

        T top() {
            return head->value;
        }

        bool pop() {
            if (isEmpty()) return false;
            const Node<T> *tmp = head;
            head = head->next;
            delete tmp;
            return true;
        }

        T popped() {
            const Node<T> *tmp = head;
            T value = head->value;
            head = head->next;
            delete tmp;
            return value;
        }
};

struct Student {
    string name;
    double score;
};

Student makeStudent(const string &name, const double score) {
    Student student;
    student.name = name;
    student.score = score;
    return student;
}

int main() {

    Stack<Student>* s = new Stack<Student>();

    const Student s1 = makeStudent("Alice", 88.6);
    const Student s2 = makeStudent("Bob", 92.4);
    const Student s3 = makeStudent("Cathy", 78.2);
    const Student s4 = makeStudent("David", 87.8);
    const Student s5 = makeStudent("Eve", 91.5);

    s->push(s1);
    s->push(s2);
    s->push(s3);
    s->push(s4);
    s->push(s5);

    cout << "Top name: " << s->top().name << endl;
    cout << "Top score: " << s->top().score << endl;

    s->pop();

    Student student = s->popped();
    cout << "Popped name: " << student.name << endl;
    cout << "Popped score: " << student.score << endl;

    delete s;
    return 0;
}
