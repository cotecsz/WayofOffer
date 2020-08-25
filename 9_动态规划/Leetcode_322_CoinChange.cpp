//
// Created by Yang Shuangzhen on 2020/8/25.
//

#include <vector>

/*
 *  Leetcode 32: 凑零钱
 *      思路：动态规划四部曲
 *      1. 确定状态，即变量
 *          amount
 *      2. 确定dp函数定义，即dp[i]含义
 *          表示amount金额需要最少dp[amount]个硬币
 *      3. 确定 选择并择优， 状态转移方程
 *          对于每个硬币：dp[i] = min{dp[i], dp[i-coin]}
 *      4. 确定base case
 *          dp[0] = 0
 */

class Solution{
public:
    int coinChange(std::vector<int>& coins, int amount){
        //  初值设为amount+1，dp[i] 最多需要i个，i<amount,
        //  所以amount 对于dp[i] 为无穷大，便于后面取最小值
        std::vector<int> dp(amount+1, amount+1);
        dp[0] = 0;

        // 依次求得amount的最小硬币数，即 dp[i]
        for (int i=0; i<dp.size(); i++){
            for (int coin : coins){
                if (i-coin < 0) continue;
                dp[i] = std::min(dp[i], 1+dp[i-coin]);
            }
        }

        return (dp[amount] == amount+1) ? -1 : dp[amount];
    }
};


int main(){
    std::vector<int> coins = {1, 2, 5};
    Solution sol;
    assert(sol.coinChange(coins, 11) == 3);

    return 0;
}