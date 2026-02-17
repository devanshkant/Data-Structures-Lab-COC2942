#include "../../custom-headers/Trees/bt.h"
#include<cstdlib>
using namespace std;
#define Tree Tree<int>

void io(Tree *root, int *index, int *ans){
    if(root == nullptr)
    {
        return;
    }
    io(root->left, index, ans);
    ans[*index] = root->val;
    (*index)++;
    io(root->right, index, ans);
}
int countNodes(Tree* root){
    return root == nullptr? 0 : 1 + countNodes(root->left) + countNodes(root->right);
}
int* inorderTraversal(Tree* root, int* returnSize) {
    *returnSize = countNodes(root);
    if (*returnSize == 0) return nullptr;
    auto result = static_cast<int*>(malloc(*returnSize * sizeof(int)));
    int index = 0;
    io(root, &index, result);
    return result;
}
