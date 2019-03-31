// CS106B: Programming Abstractions Assignment 8 Problem 5
// code to print binary tree is from www.geeksforgeeks.org/print-binary-tree-2-dimensions/

#include <iostream>
#include <vector>

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
    root->key = "Pear";
    
    nodeT * left = new nodeT;
    left->key = "Dragonfruit";
    
    root->left = left;
    root->right = NULL;
    
    left->left = NULL;
    left->right = NULL;
    
    return root;
}

nodeT * buildFruitTree3() {
    nodeT * root = new nodeT;
    root->key = "Lychee";
    
    nodeT * left = new nodeT;
    left->key = "Banana";
    
    nodeT * left1 = new nodeT;
    left1->key = "Apple";
    nodeT * right1 = new nodeT;
    right1->key = "Coconut";
    
    root->left = left;
    root->right = NULL;
    
    left->left = left1;
    left->right = right1;
    
    left1->left = NULL;
    right1->left = NULL;
    left1->right = NULL;
    right1->right = NULL;
    
    return root;
}

// helper function for treeHeight that finds lengths of all root to leaf paths
void gatherPathLengths(nodeT * tree, int length, vector<int> & lengths) {
    if (tree->left == NULL && tree->right == NULL) {
        lengths.push_back(length);
    } else {
        if (tree->left)
            gatherPathLengths(tree->left, length + 1, lengths);
        else
            gatherPathLengths(tree->right, length + 1, lengths);
    }
}

int treeHeight(nodeT * tree) {
    vector<int> pathLengths;
    gatherPathLengths(tree, 1, pathLengths);
    
    // finds longest root to leaf path length as the height
    int height = -1;
    for (int i = 0; i < pathLengths.size(); i++) {
        if (pathLengths[i] > height)
            height = pathLengths[i];
    }
    
    return height;
}

bool isBalanced(nodeT * tree) {
    if (tree->left && tree->right) {
        if (!(abs(treeHeight(tree->left) - treeHeight(tree->right)) <= 1))
            return false;
    }
    
    if (tree->left)
        isBalanced(tree->left);
    if (tree->right)
        isBalanced(tree->right);
    
    return true;
}

int main() {
    nodeT * test1 = buildFruitTree1();
    nodeT * test2 = buildFruitTree2();
    nodeT * test3 = buildFruitTree3();
    
    cout << "Fruit tree 1:" << endl;
    print2D(test1);
    cout << endl;
    
    cout << "Fruit tree 2:" << endl;
    print2D(test2);
    cout << endl;
    
    cout << "Fruit tree 3:" << endl;
    print2D(test3);
    cout << endl;
    
    if (isBalanced(test1))
        cout << "Fruit tree 1 is balanced." << endl;
    else
        cout << "Fruit tree 1 is not balanced." << endl;
    
    if (isBalanced(test2))
        cout << "Fruit tree 2 is balanced." << endl;
    else
        cout << "Fruit tree 2 is not balanced." << endl;
    
    if (isBalanced(test3))
        cout << "Fruit tree 3 is balanced." << endl;
    else
        cout << "Fruit tree 3 is not balanced." << endl;
    
    return 0;
}
