//
// Created by Yang Shuangzhen on 2020/8/25.
//


#include <vector>

/*
 * Leetcode 153: 最大子序和
 *      基本思路：与198打家劫舍不同，dp[i] 保存以第i个数为结尾的子序和
 *      dp[i] = max{ dp[i-1]+nums[i], nums[i]}
 *
 *      时间复杂度：O(n)
 */

class Solution{
public:
    int maxSubArray(std::vector<int>& nums) {
        std::vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        int maxRes = dp[0];
        for (int i=1; i< nums.size(); i++){
            dp[i] = std::max(dp[i-1]+nums[i], nums[i]);
            if (maxRes < dp[i]){
                maxRes = dp[i];
            }
        }

        return maxRes;
    }
};


int main(){
    std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution sol;
    assert(sol.maxSubArray(nums) == 6);

    return 0;
}
