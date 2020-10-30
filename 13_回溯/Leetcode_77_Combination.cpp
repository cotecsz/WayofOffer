//
// Created by Yang Shuangzhen on 2020/10/30.
//

#include <vector>

/*
 * Leetcode 77 经典组合
 *      回溯法：
        void backtracking(参数) {
            if (终止条件) {
                存放结果;
                return;
            }

            for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
                处理节点;
                backtracking(路径，选择列表); // 递归
                回溯，撤销处理结果
            }
        }
 */
class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        path.clear();
        res.clear();
        backtracing(n, k, 1);
        return res;
    }

private:
    std::vector<int> path;
    std::vector<std::vector<int>> res;

    void backtracing(int n, int k, int startIndex){
        if (path.size() == 2){
            res.push_back(path);
            return ;
        }

        for (int i=startIndex; i<=n; i++){
            path.push_back(i);
            backtracing(n, k, i+1);
            path.pop_back();
        }
    }
};

int main(){
    std::vector<int> a{12, 13};
    std::vector<std::vector<int>> res {  {1, 2},
                                         {1, 3},
                                         {1, 4},
                                         {2, 3},
                                         {2, 4},
                                         {3, 4},
                                         };
    Solution sol;
    assert(sol.combine(4, 2) == res);
    return 0;
}
