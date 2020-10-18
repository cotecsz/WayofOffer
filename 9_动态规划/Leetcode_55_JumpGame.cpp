//
// Created by Yang Shuangzhen on 2020/10/18.
//

#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        if (nums.size() <= 1)   return true;

        int n = nums.size();
        std::vector<bool> dp(n, false);

        dp[0] = true;
        for (int i=1; i < n; i++){
            for (int j=0; j < i; j++ ){
                if (dp[j] && j+nums[j] >= i){
                    dp[i] =  true;
                    break;
                }
            }
        }

        return dp[n-1];
    }
};

int main(){
    std::vector<int> nums{2,3,1,1,4};
    std::vector<int> nums2{3, 2, 1, 0, 4};

    Solution sol;
    assert(sol.canJump(nums));

    assert(!sol.canJump(nums2));
    return 0;
}