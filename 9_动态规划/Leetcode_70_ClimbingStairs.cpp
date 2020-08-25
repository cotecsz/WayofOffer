//
// Created by Yang Shuangzhen on 2020/8/25.
//

#include <vector>

/*
 * Leetcode 70: 爬楼梯
 *      思路：dp[n] = dp[n-1] + dp[n-2]
 */
class Solution{
public:
    int climbStairs(int n){
        std::vector<int> dp(n+3, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i=3; i<=n; i++)
            dp[i] = dp[i-1] + dp[i-2];

        return dp[n];
    }
};

int main(){
    Solution sol;
    assert(sol.climbStairs(4) == 5);
    return 0;
}