#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//construct binary tree from instructions in input file
struct tree
{
    int val;
    struct tree* left;
    struct tree* right;
    tree(const int value): val(value), left(nullptr), right(nullptr) {}
};
int get_num(const string s, int start, const int end)
{
    int ans = 0;
    while (start <= end)
    {
        int digit = s[start] - '0';
        ans = ans*10 + digit;
        start++;
    }
    return ans;
}

void inorder(const tree *root)
{
    if (not root)    return;
    inorder(root->left);
    cout << root->val << ' ';
    inorder(root->right);
}

int main(){
    ifstream file("input_lab5.txt");
    string line;
    getline(file, line);
    int root_value = get_num(line, 0, line.size() - 1);
    auto root = new tree(root_value);
    while (getline(file, line)){
        auto *temp = root;
        int i = 0;
        while (i < line.size() and (line[i] == 'L' or line[i] == 'R')){
            if (temp->left == nullptr and line[i] == 'L'){
                int curr_num = get_num(line, i + 1, line.length() - 1);
                temp->left = new tree(curr_num);
                ++i;
                break;
            }
            if (temp->right == nullptr and line[i] == 'R'){
                int curr_num = get_num(line, i + 1, line.length() - 1);
                temp->right = new tree(curr_num);
                ++i;
                break;
            }
            if (line[i] == 'R'){
                temp = temp->right;
                ++i;
            }
            if (line[i] == 'L'){
                temp = temp->left;
                ++i;
            }
        }
    }
    inorder(root);

}