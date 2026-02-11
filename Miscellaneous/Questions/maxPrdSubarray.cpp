/*
    7. Maximum subarray product — handle positives/negatives to track max product subarray.
    Real life: maximize compounded growth over contiguous periods with gains/losses.

*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProductSubarray(const vector<int>& nums) {
    int maxP = nums[0];
    int minP = nums[0];
    int ans = nums[0];

    for (size_t i = 1; i < nums.size(); i++) {
        int curr = nums[i];
        // swapping when negative appears 
        if (curr < 0) {
            swap(maxP, minP);
        }

        maxP = max(curr, maxP * curr);
        minP = min(curr, minP * curr);

        ans = max(ans, maxP);
    }
    return ans;
}

int main() {
    vector<int> nums = {2, 3, -2, 4, -1};
    cout << "Maximum Subarray Product = " << maxProductSubarray(nums) << endl;
    return 0;
}