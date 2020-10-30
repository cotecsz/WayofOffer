//
// Created by Yang Shuangzhen on 2020/10/30.
//

#include <vector>
/*
 * Leetcode 216: 组合总和III
 *      基本思路：回溯法套路。
 */
class Solution {
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        path.clear();
        res.clear();
        backtracing(k, n, 0, 1);

        return res;
    }

private:
    std::vector<int> path;
    std::vector<std::vector<int>> res;
    void backtracing(int k, int targetSum, int sum, int startIndex){
        // 剪枝
        if (sum > targetSum){
            return ;
        }

        if (path.size() == k){
            if (sum == targetSum)   res.push_back(path);
            return ;        // 若和不为target ，直接返回
        }

        for (int i=startIndex; i<9; i++){
            path.push_back(i);
            // sum += i;
            backtracing(k, targetSum, sum+i, i+1);
            // sum -= i;
            path.pop_back();
        }
    }
};

int main(){
    int k = 3, n = 9;
    std::vector<std::vector<int>> res = {{1, 2, 6},
                                         {1, 3, 5},
                                         {2, 3, 4}};

    Solution sol;
    assert(sol.combinationSum3(k, n) == res);
    return 0;
}