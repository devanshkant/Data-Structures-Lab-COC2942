#include <iostream>
#include "../../custom-headers/Trees/bt.h"
using namespace std;
#define Tree Tree<int>

//this form the tree in preorder traversal
Tree* createTree() {
    int x;
    cout << "Enter node value(-1 for null) = ";
    cin >> x;

    if(x == -1)
        return nullptr;

    auto *root = new Tree(x);
    root->left = createTree();
    root->right = createTree();

    return root;
}

int main() {

}