//
// Created by Yang Shuangzhen on 2020/8/25.
//

#include <vector>

/*
 * Leetcode 198: 打家劫舍
 *      基本思路：使用动态规划，确定递推方程，边界条件。
 *      遍历每个元素，判读是否选择：
 *          dp[i] = max{dp[i-2]+nums[i], dp[i-1]}
 */

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.size() == 0){
            return 0;
        }
        if (nums.size() == 1){
            return nums[0];
        }

        std::vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for (int i=2; i< nums.size(); i++){
            dp[i] = std::max(dp[i-2]+nums[i], dp[i-1]);
        }

        return dp[nums.size()-1];
    }
};

int main(){
    std::vector<int> nums = {5, 2, 6, 3, 4, 9};
    Solution sol;
    assert(sol.rob(nums) == 20);

    return 0;
}
