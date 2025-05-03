/*
要求：把递增数组的前面部分数字移到队尾，求数组中的最小值，例如[3,4,5,6,1,2]
思路：使用二分法，但要考虑[1, 0, 0, 1]这种数据，只能顺序查找
*/

#include <iostream>
#include <vector>

using namespace std;

// 1, 4, 8
// 4, 8, 1
// 8, 1, 4

int find_min(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    while (l < r) {
        // cout << l << ", " << r << endl;
        int m = (l + r + 1) / 2;
        if (nums[l] <= nums[m] && nums[m] <= nums[r]) {
            return nums[l];
        }
        if (nums[l] <= nums[m] && nums[m] > nums[r]) {
            l = m + 1;
            continue;
        }
        if (nums[l] > nums[m] && nums[m] <= nums[r]) {
            r = m;
            continue;
        }
    }
    return nums[l];
}

int main() {
    // std::vector<int> nums({3, 4, 5, 5, 1, 2});
    std::vector<int> nums({0, 1, 1, 0, 0, 0});
    std::cout << find_min(nums) << std::endl;
    return 0;
}
