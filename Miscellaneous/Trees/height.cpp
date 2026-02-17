#include<iostream>
#include "../../custom-headers/Trees/bt.h"
#define Tree Tree<int>
int height(const Tree* root) {
    if (root == nullptr)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + std::max(leftHeight, rightHeight);
}