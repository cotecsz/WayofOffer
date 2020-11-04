//
// Created by Yang Shuangzhen on 2020/11/4.
//
#include <vector>
/*
 * Leetcode40 组合总和II
 *     基本思路：重点是不能出现重复的组合，之前的层数已经使用过，则直接下一次
 *
 *     使用used 来表示是否使用过
 *     used[i-1] = true : 该树枝使用过过
 *     used[i-1] = false : 该树曾使用过
 *
 *     剪枝优化：同39 组合求和。当候选数与sum相加大于target，则直接遍历下一个数
 */
class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        path.clear();
        res.clear();
        std::vector<bool> used(candidates.size(), false);
        std::sort(candidates.begin(), candidates.end());
        backtracing(candidates, target, 0, 0, used);
        return res;
    }

private:
    std::vector<int> path;
    std::vector<std::vector<int>> res;
    std::vector<bool> used;

    void backtracing(std::vector<int>& candiates, int target, int startIndex, int sum, std::vector<bool>& used){
        if (sum > target){
            return ;
        }
        if (sum == target){
            res.push_back(path);
            return ;
        }

        for (int i=startIndex; i<candiates.size(); i++){

            if (i > 0 && candiates[i] == candiates[i-1] && used[i-1] == false){
                continue;
            }
            sum += candiates[i];
            used[i] = true;
            path.push_back(candiates[i]);
            backtracing(candiates, target, i+1, sum, used);
            path.pop_back();
            used[i] = false;
            sum -= candiates[i];
        }
    }
};

class SolutionPrune{
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        path.clear();
        res.clear();
        std::vector<bool> used(candidates.size(), false);
        std::sort(candidates.begin(), candidates.end());
        backtracing(candidates, target, 0, 0, used);
        return res;
    }

private:
    std::vector<std::vector<int>> res;
    std::vector<int> path;

    void backtracing(std::vector<int>& candidates, int target, int startIndex, int sum, std::vector<bool>& used){
        if (sum == target){
            res.push_back(path);
            return ;
        }

        for (int i=startIndex; i<candidates.size(); i++){
            if (i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false){
                continue;
            }
            if (sum + candidates[i] > target){
                continue;
            }

            path.push_back(candidates[i]);
            sum += candidates[i];
            used[i] = true;
            backtracing(candidates, target, i+1, sum, used);
            used[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
    }
    };
int main(){
    std::vector<int> candidates{2,5,2,1,2};
    int target = 5;
    std::vector<std::vector<int>> res {  {1, 2, 2},
                                         {5}
    };
    Solution sol;
    assert(sol.combinationSum2(candidates, target) == res);

    SolutionPrune solPru;
    assert(solPru.combinationSum2(candidates, target) == res);
    return 0;
}