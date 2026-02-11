/*
    9. Product except self (pre & suf products) — compute product of array except current index without division.
    Real life: compute influence of all other investors on a stock excluding one.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> preXsuf(const vector<int>& nums) {
    int n = nums.size();
    vector<int> pre(n, 1), suf(n, 1), ans(n);
    // pre
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] * nums[i - 1];
    }
    // suf
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1] * nums[i + 1];
    }
    //  product
    for (int i = 0; i < n; i++) {
        ans[i] = pre[i] * suf[i];
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> output = preXsuf(nums);

    cout << "Output: ";
    for (int val : output) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}  