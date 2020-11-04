//
// Created by Yang Shuangzhen on 2020/11/4.
//

#include <vector>
/*
 * Leetcode39 : 组合总和
 *     基本思路：回溯法逐个遍历元素，加入path，当sum和为target，则保存，否则回溯回去。
 *
 */
class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        path.clear();
        res.clear();
        backtracing(candidates, target, 0, 0);

        return res;
    }

private:
    std::vector<int> path;
    std::vector<std::vector<int>> res;
    void backtracing(std::vector<int>& candidates, int target, int startIndex, int sum){
        if (sum > target){
            return ;
        }
        if (sum == target){
            res.push_back(path);
            return ;
        }

        for (int i=startIndex; i < candidates.size(); i++){
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracing(candidates, target, i, sum);
            sum -= candidates[i];
            path.pop_back();
        }
    }
};

/*
 * 剪枝优化：
 *     基本思路：
 */
class SolutionPrune {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        path.clear();
        res.clear();
        backtracing(candidates, target, 0, 0);
        return res;
    }

private:
    std::vector<int> path;
    std::vector<std::vector<int>> res;

    void backtracing(std::vector<int>& candidates, int target, int startIndex, int sum){
        if (sum > target){
            return ;
        }
        if (sum == target){
            res.push_back(path);
            return ;
        }

        for (int i=startIndex; i < candidates.size(); i++){
            if (sum + candidates[i] > target){
                continue;
            }

            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracing(candidates, target, i, sum);
            sum -= candidates[i];
            path.pop_back();
        }
    }
};

int main(){
    std::vector<int> candidates{2,3,5};
    int target = 8;
    std::vector<std::vector<int>> res {{2,2,2,2},
                                       {2,3,3},
                                       {3, 5}};
    Solution sol;
    assert(sol.combinationSum(candidates, target) == res);

    SolutionPrune solPru;
    assert(solPru.combinationSum(candidates, target) == res);
    return 0;
}