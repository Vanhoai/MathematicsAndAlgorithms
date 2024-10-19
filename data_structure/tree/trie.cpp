#include <iostream>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

TrieNode *getNode() {
    TrieNode *node = new TrieNode;
    node->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = nullptr;
    }

    return node;
}

void insert(TrieNode *root, string key) {
    TrieNode *node = root;

    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!node->children[index]) {
            node->children[index] = getNode();
        }
        node = node->children[index];
    }

    node->isEndOfWord = true;
}

bool search(TrieNode *root, string key) {
    TrieNode *node = root;
