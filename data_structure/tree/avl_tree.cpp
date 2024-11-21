#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    int height;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int value)
        : value(value), left(nullptr), right(nullptr), height(1) {
        cout << "TreeNode(" << value << ")" << endl;
    }
};

class AVLTree {
public:
    TreeNode *root;
    AVLTree() { root = nullptr; }

    int height(TreeNode *node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int getBalanceFactor(TreeNode *node) {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    TreeNode *rotateRight(TreeNode *y) {
        TreeNode *x = y->left;
        TreeNode *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    TreeNode *rotateLeft(TreeNode *y) {
        TreeNode *x = y->right;
        TreeNode *T2 = x->left;

        x->left = y;
        y->right = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    TreeNode *insertNode(TreeNode *node, int value) {
        if (node == nullptr)
            return new TreeNode(value);

        if (value < node->value)
            node->left = insertNode(node->left, value);
        else if (value > node->value)
            node->right = insertNode(node->right, value);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int balanceFactor = getBalanceFactor(node);

        // LL Case
        if (balanceFactor > 1 && value < node->left->value)
            return rotateRight(node);

        // RR Case
        if (balanceFactor < -1 && value > node->right->value)
            return rotateLeft(node);

        // LR Case
        if (balanceFactor > 1 && value > node->left->value) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // RL Case
        if (balanceFactor < -1 && value < node->right->value) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void preOrder(TreeNode *root) const {
        if (root == nullptr)
            return;
        cout << root->value << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
};

int main_dev() {
    AVLTree *tree;

    tree->insertNode(tree->root, 10);
    tree->insertNode(tree->root, 20);
    tree->insertNode(tree->root, 30);
    tree->insertNode(tree->root, 40);
    tree->insertNode(tree->root, 50);
    tree->insertNode(tree->root, 25);

    tree->preOrder(tree->root);
    cout << endl;

    return 0;
}