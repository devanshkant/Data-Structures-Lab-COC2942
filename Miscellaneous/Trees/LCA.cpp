#include <utility>
#include"../../custom-headers/Trees/bt.h"
using namespace std;
#define Tree Tree<int>
/*
 *this resulting pair stores result as:
        pair.first == num_target_nodes
        pair.second == ancestor
*/
pair<int, Tree*> LCAHelper(Tree* root, Tree* p, Tree* q){
    if(not root)
        return std::make_pair(0, nullptr);
    auto left_result = LCAHelper(root->left, p, q);
    if(left_result.first == 2){
        return left_result;
    }
    auto right_result = LCAHelper(root->right, p, q);
    if(right_result.first == 2){
        return right_result;
    }
    int num_target_nodes = left_result.first + right_result.first +
                            (root == p) + (root == q);
    return std::make_pair(num_target_nodes, num_target_nodes == 2? root : nullptr);
}
Tree* lowestCommonAncestor(Tree* root, Tree* p, Tree* q) {
    return LCAHelper(root, p, q).second;
}

int main() {

}

