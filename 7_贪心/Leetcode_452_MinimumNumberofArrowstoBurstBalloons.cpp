//
// Created by Yang Shuangzhen on 2020/10/18.
//

#include <vector>

/*
 * Leetcode 452: 射击气球
 *      基本思路：使用 rightInterval 记录射击区间。
 *      1. 使用左端点对 points 排序
 *      2. 区间右端点 与 piont 左端点比较
 */
class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) {
        if (points.size() == 0)   return 0;

        std::sort(points.begin(), points.end(), cmp);
        int arrowCount = 1;
        int rightInterval = points[0][1];
        for (int i=1; i<points.size(); i++){
            if (rightInterval > points[i][0]){      // 右端点 >  新的左端点，则无需新的箭
                // 右端点 > 新的右端点，缩小射击区间
                rightInterval = std::min(rightInterval, points[i][1]);
            }
            else {                                  // 右端点 < 新的左端点，arrowCount+1, 更新射击区间
                arrowCount++;
                rightInterval = points[i][1];
            }
        }

        return arrowCount;
    }
private:
    static bool cmp(const std::vector<int>& point1, const std::vector<int>& point2){
        return point1[0] < point2[0];
    }
};

int main(){
    std::vector<std::vector<int>> points{{10, 16},
                                         {2, 8},
                                         {1, 6},
                                         {7, 12}};

    Solution sol;
    assert(sol.findMinArrowShots(points) == 2);

    return 0;
}