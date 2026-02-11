/*13. Next permutation (lexicographic successor) — rearrange array into next permutation in-place.
Real life: generate the next candidate PIN/code in a sequence.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    // Step 1: Find the pivot
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        // Step 2: Find rightmost successor
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(nums[i], nums[j]);
    }

    // Step 3: Reverse suffix
    reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    vector<int> nums = {1, 2, 3};
    nextPermutation(nums);

    cout << "Next Permutation: ";
    for (int val : nums) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}


/*
using STL

int main() {
    vector<int> nums = {1, 2, 3};

    // STL provides next_permutation directly
    if (next_permutation(nums.begin(), nums.end())) {
        cout << "Next Permutation: ";
    } else {
        cout << "No next permutation, reset to smallest: ";
    }

    for (int val : nums) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}



*/