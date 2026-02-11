/*11. Stable in-place partition (move zeroes / move negatives) — move certain elements to one side while preserving order.
Real life: move completed tasks to the back of a task list while preserving their original order.
*/

#include <iostream>
#include <vector>
using namespace std;

void moveZeroesStable(vector<int>& nums) {
    int n = nums.size();
    int insertPos = 0;

    // First pass: move non-zero elements forward
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[insertPos++] = nums[i];
        }
    }

    // Fill remaining positions with zeroes
    while (insertPos < n) {
        nums[insertPos++] = 0;
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroesStable(nums);

    cout << "After stable partition: ";
    for (int val : nums) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}