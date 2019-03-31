// CS106B: Programming Abstractions Assignment 8 Problem 3

#include <iostream>

using namespace std;

struct nodeT {
    string key;
    nodeT * left;
    nodeT * right;
};

void printBinaryTree(nodeT * tree) {
    
}

bool treeEqual(nodeT * tree1, nodeT * tree2) {
    if (tree1->key != tree2->key) {
        return false;
    } else if (tree1->left == NULL && tree2->left != NULL) {
        return false;
    } else if (tree1->right == NULL && tree2->right != NULL) {
        return false;
    } else if (tree1->left != NULL && tree2->left == NULL) {
        return false;
    } else if (tree1->right != NULL && tree2->right == NULL) {
        return false;
    } else {
        treeEqual(tree1->left, tree2->left);
        treeEqual(tree1->right, tree2->right);
    }
    
    return true;
}

int main() {
    
    return 0;
}
