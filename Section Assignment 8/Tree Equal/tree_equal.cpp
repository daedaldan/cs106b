// CS106B: Programming Abstractions Assignment 8 Problem 3
// code to print binary tree is from www.geeksforgeeks.org/print-binary-tree-2-dimensions/

#include <iostream>

using namespace std;

struct nodeT {
    string key;
    nodeT * left;
    nodeT * right;
};

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(nodeT * root, int space) {
    // Base case
    if (root == NULL)
        return;
    
    // Increase distance between levels
    space += 10;
    
    // Process right child first
    print2DUtil(root->right, space);
    
    // Print current node after space
    // count
    cout<<endl;
    for (int i = 10; i < space; i++)
        cout<<" ";
    cout<<root->key<<"\n";
    
    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(nodeT * root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

nodeT * buildFruitTree1() {
    nodeT * root = new nodeT;
    root->key = "Orange";
    
    nodeT * left = new nodeT;
    left->key = "Pear";
    nodeT * right = new nodeT;
    right->key = "Watermelon";
    
    nodeT * left1 = new nodeT;
    left1->key = "Apple";
    nodeT * right1 = new nodeT;
    right1->key = "Coconut";
    
    nodeT * left2 = new nodeT;
    left2->key = "Strawberry";
    nodeT * right2 = new nodeT;
    right2->key = "Pineapple";
    
    root->left = left;
    root->right = right;
    
    left->left = left1;
    left->right = right1;
    
    right->left = left2;
    right->right = right2;
    
    left1->left = NULL;
    right1->left = NULL;
    left1->right = NULL;
    right1->right = NULL;
    left2->left = NULL;
    right2->left = NULL;
    left2->right = NULL;
    right2->right = NULL;
    
    return root;
}

nodeT * buildFruitTree2() {
    nodeT * root = new nodeT;
    root->key = "Lychee";
    
    nodeT * left = new nodeT;
    left->key = "Banana";
    nodeT * right = new nodeT;
    right->key = "Watermelon";
    
    nodeT * left1 = new nodeT;
    left1->key = "Apple";
    nodeT * right1 = new nodeT;
    right1->key = "Coconut";
    
    nodeT * left2 = new nodeT;
    left2->key = "Kiwi";
    nodeT * right2 = new nodeT;
    right2->key = "Pineapple";
    
    root->left = left;
    root->right = right;
    
    left->left = left1;
    left->right = right1;
    
    right->left = left2;
    right->right = right2;
    
    left1->left = NULL;
    right1->left = NULL;
    left1->right = NULL;
    right1->right = NULL;
    left2->left = NULL;
    right2->left = NULL;
    left2->right = NULL;
    right2->right = NULL;
    
    return root;
}

nodeT * buildFruitTree3() {
    nodeT * root = new nodeT;
    root->key = "Pear";
    
    nodeT * left = new nodeT;
    left->key = "Dragonfruit";
    nodeT * right = new nodeT;
    right->key = "Apple";
    
    
    root->left = left;
    root->right = right;
    
    left->left = NULL;
    right->left = NULL;
    left->right = NULL;
    right->right = NULL;

    return root;
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
    } else if ((tree1->left == NULL && tree2->left == NULL) || (tree1->right == NULL && tree2->right == NULL)) {
        // do nothing
    } else {
        treeEqual(tree1->left, tree2->left);
        treeEqual(tree1->right, tree2->right);
    }
    
    return true;
}

int main() {
    nodeT * test1 = buildFruitTree1();
    nodeT * test2 = buildFruitTree2();
    nodeT * test3 = buildFruitTree3();
    nodeT * test4 = buildFruitTree1();
    
    if (treeEqual(test1, test4))
        cout << "Fruit tree 1 is equal to fruit tree 4" << endl;
    else
        cout << "Fruit tree 1 is not equal to fruit tree 4" << endl;
    
    if (treeEqual(test1, test2))
        cout << "Fruit tree 1 is equal to fruit tree 2" << endl;
    else
        cout << "Fruit tree 1 is not equal to fruit tree 2" << endl;
    
    if (treeEqual(test2, test3))
        cout << "Fruit tree 2 is equal to fruit tree 3" << endl;
    else
        cout << "Fruit tree 2 is not equal to fruit tree 3" << endl;
    
    return 0;
}
