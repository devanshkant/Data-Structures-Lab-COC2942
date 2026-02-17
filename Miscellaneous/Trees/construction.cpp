#include "../../custom-headers/Trees/bt.h"
using namespace std;
#include<iostream>
//construct BT from inorder + preorder traversal
/**
 * preorder's first element : root
 * find root in inorder: splits into left and right subtrees
 * recurse
*/
#define Tree Tree<int>

int search(int arr[], int start, int end, int val){
    for (int i = start; i <= end; i++)
        if (arr[i] == val)
            return i;
    return -1;
}

int preIndex = 0;
Tree* buildFromInPre(int inorder[], int preorder[], int inStart, int inEnd)
{
    if (inStart > inEnd) return nullptr;
    auto root = new Tree(preorder[preIndex++]);
    if (inStart == inEnd)
        return root;
    int inIdx = search(inorder, inStart, inEnd, root->val);
    root->left = buildFromInPre(inorder, preorder, inStart, inIdx-1);
    root->right = buildFromInPre(inorder, preorder, inIdx+1, inEnd);
    return root;
}
//construct BT from inorder + postorder traversal

int postIdx;
Tree* buildFromInPost(int inorder[], int postorder[], int inStart, int inEnd)
{
    if (inStart > inEnd)    return nullptr;
    auto root = new Tree(postorder[postIdx--]);
    if (inStart == inEnd)   return root;
    int inIdx = search(inorder, inStart, inEnd, root->val);
    root->right = buildFromInPost(inorder, postorder, inIdx + 1, inEnd);
    root->left =  buildFromInPost(inorder, postorder, inStart, inIdx - 1);
    return root;
}

int main()
{
    int n ;
    cout << "Enter the number of elements in the tree";
    cin >> n;
    auto *inorder = new int[n], *preorder = new int[n];
    cout << "Enter elements in inorder traversal : ";
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }
    cout << "Enter elements in preorder traversal : ";
    for (int i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }
    Tree* root = buildFromInPre(inorder, preorder, 0, n-1);

}