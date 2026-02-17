#include<iostream>
#include "../../custom-headers/Trees/bt.h"
#define Tree Tree<int>
using namespace std;
struct Status
{
    int first;
    int second;
    Status(int a, int b): first(a), second(b) {}
};
Status diameterHelper(const Tree* root) {
    if (not root )
    {
        Status ans(0,0);
        return ans;
    }

    Status left = diameterHelper(root->left);
    Status right = diameterHelper(root->right);
    int op1 = left.first,
        op2 = right.first,
        op3 = left.second + right.second + 1;
    Status ans(0,0);
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
int diameter(const Tree* root) {
    return diameterHelper(root).first;
}
