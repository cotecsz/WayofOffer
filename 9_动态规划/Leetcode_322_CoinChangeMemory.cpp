//
// Created by Yang Shuangzhen on 2020/10/3.
//

#include <vector>

class Solution{
public:
    int GetMinCountHelper(int total, std::vector<int>& values, std::vector<int>& memo){
        if (memo[total] != -2)		return memo[total];

        int minCount = INT_MAX;
        for (int i=0; i<values.size(); i++){
            // 当硬币面值大于总钱数
            if (values[i] > total)	continue;

            // 使用当前硬币
            int rest = total - values[i];
            int restCount = GetMinCountHelper(rest, values, memo);

            // 无可用组合
            if (restCount == -1)		continue;

            // int totalCount = 1 + restCount;
            // minCount = totalCount; // totalCount < minCount ? totalCount : minCount;
            minCount = 1 + restCount;
        }

        // 硬币都无法满足要求
        if (minCount == INT_MAX){
            memo[total] = -1;
            return -1;
        }

        memo[total] = minCount;
        return minCount;
    }

    int GetMinCount(){
        std::vector<int> values{3, 5};
        int total = 11;

        std::vector<int> memo(total+1, -2);
        memo[0] = 0;
        return GetMinCountHelper(total, values, memo);
    }
};

int main(){
    Solution sol;
    assert(sol.GetMinCount() == 3);
}
