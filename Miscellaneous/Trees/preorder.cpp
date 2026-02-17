#include "../../custom-headers/Trees/bt.h"
#include<cstdlib>
#define Tree Tree<int>
int countNodes(Tree* root){
    return root == nullptr? 0 : 1 + countNodes(root->left) + countNodes(root->right);
}

void preorderHelper(Tree* root, int* index, int* result) {
    if (root == nullptr) return;

    result[(*index)++] = root->val;
    preorderHelper(root->left,  index, result);
    preorderHelper(root->right, index, result);
}

int* preorderTraversal(Tree* root, int* returnSize) {
    *returnSize = countNodes(root);

    if (*returnSize == 0) return nullptr;

    auto result = static_cast<int*>(malloc((*returnSize) * sizeof(int)));
    if (result == nullptr) { *returnSize = 0; return nullptr; }

    int index = 0;
    preorderHelper(root, &index, result);
    return result;
}