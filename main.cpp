
#include "libraries.cpp"
using namespace std;

struct Node {
    int value;
    int height;
    Node *start, *end;

    Node(int value) {
        this->value = value;
        this->height = 0;
        this->start = nullptr;
        this->end = nullptr;
    }
};

class AVLTree {
private:
    Node *root;

    Node *createNode(int value) {
        Node *node = new Node(value);
        return node;
    }

public:
    AVLTree() { root = nullptr; }

    Node *insertNode(Node *root, int value) {}
};

int main() {
    FAST_IO;
    READ_WRITE_FILE();

    AVLTree *tree = new AVLTree();

    return 0;
}