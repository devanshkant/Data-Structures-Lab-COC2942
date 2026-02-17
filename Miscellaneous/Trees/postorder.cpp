#include "../../custom-headers/Trees/bt.h"
#include<cstdlib>
#define Tree Tree<int>
int countNodes(Tree* root){
    return root == nullptr? 0 : 1 + countNodes(root->left) + countNodes(root->right);
}

void postorderHelper(Tree* root, int* index, int* result) {
    if (root == nullptr) return;

    postorderHelper(root->left,  index, result);
    postorderHelper(root->right, index, result);
    result[(*index)++] = root->val;
}

int* postorderTraversal(Tree* root, int* returnSize) {
    *returnSize = countNodes(root);

    if (*returnSize == 0) return nullptr;

    auto result = static_cast<int*>(malloc((*returnSize) * sizeof(int)));
    if (result == nullptr) { *returnSize = 0; return nullptr; }

    int index = 0;
    postorderHelper(root, &index, result);
    return result;
}

