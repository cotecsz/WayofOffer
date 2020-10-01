//
// Created by Yang Shuangzhen on 2020/10/1.
//

#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        if (amount == 0)    return 0;
        std::sort(coins.rbegin(), coins.rend());
        int ans = INT_MAX;
        dfsHelper(coins, amount, 0, 0, ans);
        return ans == INT_MAX ? -1 : ans;
    }

    void dfsHelper(std::vector<int>& coins, int amount, int c_index, int count, int& ans){
        // 当余额为0时，取较小的结果
        if (amount == 0){
            ans = std::min(count, ans);
            return ;
        }
        // 当遍历完毕，直接返回
        if (c_index == coins.size()){
            return ;
        }

        for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--){
            dfsHelper(coins, amount-coins[c_index] * k, c_index+1, count+k, ans );
        }
    }
};

int main(){
    std::vector<int> coins = {1, 2, 5};
    Solution sol;
    assert(sol.coinChange(coins, 11) == 3);

    return 0;
}