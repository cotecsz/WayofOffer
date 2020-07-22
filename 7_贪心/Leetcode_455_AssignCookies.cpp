//
// Created by Yang Shuangzhen on 2020/7/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Leetcode 455 分糖果
 *      给定孩子的需求因子g数组，糖果大小数组，求出最多可以满足多少孩子的需求
 *
 *      基本思路：
 *          1. 用较小的糖果大小满足最小的需求
 *          2. 需求因子更小的更容易满足
 */

class Solution {
public:
//    int findContentChildren(vector<int>& g, vector<int>& s) {
//        int res = 0;
//        for (int cookie=0,  child=0; child<g.size() && cookie <s.size(); cookie++){
//            if (g[child] <= s[cookie]){
//                res++;
//                child++;
//            }
//
//        }
//        return res;
//    }

    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int child = 0;
        int cookie = 0;
        while (child < g.size() && cookie < s.size()){
            if (g[child] <= s[cookie]){
                child++;
            }
            cookie++;
        }
        return child;
    }
};


int main(){
    vector<int> g = {5, 9, 9, 2, 10, 15};
    vector<int> s = {6, 8, 20, 1, 3};

    Solution sol;
    int res = sol.findContentChildren(g, s);
    assert(res == 3);

    return 0;
}

