#include <iostream>
using namespace std;

template <class T> struct TreeNode {
    T value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(const T &value) : value(value), left(nullptr), right(nullptr) {
        cout << "TreeNode(" << value << ")" << endl;
    }
};

class BinaryTree final {
public:
    TreeNode<int> *root;
    BinaryTree() { root = nullptr; }
    ~BinaryTree() {}

    bool isEmpty() const { return root == nullptr; }

    void insertNode(const int &value) {
        if (isEmpty()) {
            root = new TreeNode<int>(value);
            return;
        }

        TreeNode<int> *current = root;
        while (true) {
            if (value < current->value) {
                if (current->left == nullptr) {
                    current->left = new TreeNode<int>(value);
                    return;
                }
                current = current->left;
            } else {
                if (current->right == nullptr) {
                    current->right = new TreeNode<int>(value);
                    return;
                }
                current = current->right;
            }
        }
    }

    TreeNode<int> *findMinNode(TreeNode<int> *root) const {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    TreeNode<int> *removeNode(const int &value, TreeNode<int> *root) {
        if (isEmpty())
            return nullptr;

        if (value < root->value) {
            root->left = removeNode(value, root->left);
        } else if (value > root->value) {
            root->right = removeNode(value, root->right);
        } else {
            // TH1: Current node is a leaf
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }

            // TH2: Current code has only one child
            else if (root->left == nullptr) {
                TreeNode<int> *tmp = root->right;
                delete root;
                return tmp;
            } else if (root->right == nullptr) {
                TreeNode<int> *tmp = root->left;
                delete root;
                return tmp;
            }

            // TH3: Current node with two children
            else {
                TreeNode<int> *tmp = findMinNode(root->right);
                root->value = tmp->value;
                root->right = removeNode(tmp->value, root->right);
            }
        }

        return root;
    }

    void preOrder(TreeNode<int> *root) const {
        if (root == nullptr)
            return;
        cout << root->value << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(TreeNode<int> *root) const {
        if (root == nullptr)
            return;
        inOrder(root->left);
        cout << root->value << " ";
        inOrder(root->right);
    }

    void postOrder(TreeNode<int> *root) const {
        if (root == nullptr)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->value << " ";
    }
};

//        10
//      /    \
//     5      15
//    / \    /  \
//   3   7  13  17

int main_binary_tree() {
    BinaryTree tree;
    tree.insertNode(10);
    tree.insertNode(5);
    tree.insertNode(15);
    tree.insertNode(3);
    tree.insertNode(7);
    tree.insertNode(13);
    tree.insertNode(17);

    tree.preOrder(tree.root);   // 10 5 3 7 15 13 17
    cout << endl;
    tree.inOrder(tree.root);   // 3 5 7 10 13 15 17
    cout << endl;
    tree.postOrder(tree.root);   // 3 7 5 13 17 15 10
    cout << endl;

    tree.removeNode(5, tree.root);
    //        10
    //      /    \
    //     7      15
    //    /     /   \
    //   3     13    17
    tree.preOrder(tree.root);   // 10 7 3 15 13 17
    cout << endl;

    return 0;
}