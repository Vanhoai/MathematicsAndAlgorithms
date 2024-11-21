#include <iostream>
using namespace std;

enum TReeColor { RED, BLACK };

struct RBNode {
    int value;
    RBNode *left, *right, *parent;
    TReeColor color;
    RBNode(int value) {
        this->value = value;
        left = right = parent = nullptr;
        color = RED;
    }
};

class RBTree {
private:
    RBNode *root;

public:
    RBTree() { root = nullptr; }
    ~RBTree() {}

    bool isEmpty() const { return root == nullptr; }

    RBNode *search(int value) {
        if (isEmpty())
            return nullptr;

        RBNode *current = root;
        while (current != nullptr) {
            if (value < current->value)
                current = current->left;
            else if (value > current->value)
                current = current->right;
            else
                return current;
        }

        return nullptr;
    }

    RBNode *searchWithRecursion(RBNode *node, int value) {
        if (node == nullptr)
            return nullptr;
        if (value < node->value)
            return searchWithRecursion(node->left, value);
        else if (value > node->value)
            return searchWithRecursion(node->right, value);
        else
            return node;
    }

    void *update(RBNode *node) {
        RBNode *parent = node->parent;
        RBNode *grandparent = parent->parent;
    }

    void rotateLeft(RBNode *node) {
        RBNode *R = node->right;
        node->right = R->left;
    }
};

int main_dev() { return 0; }