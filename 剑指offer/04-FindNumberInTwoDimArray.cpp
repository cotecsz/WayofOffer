//
// Created by Yang Shuangzhen on 2020/10/22.
//

#include <vector>

/*
 * 04-二维数组中查找指定数字
 *     从右上角查找，当数等于指定target，则找到
 *     若数大于指定target，则列的最小值大于target，删除该列：column--
 *     若数小于指定target，则行的最大值小于target，则删除该行：row++
 */

class Solution {
public:
    bool findNumberIn2DArray(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.size() == 0 )    return false;

        bool found = false;

        int row = 0, column = matrix[0].size()-1;
        while (row < matrix.size() && column > 0){
            if (matrix[row][column] == target){
                found = true;
                break;
            }
            else if (matrix[row][column] > target){
                column--;
            }
            else{
                row++;
            }
        }

        return found;
    }
};


int main(){
    std::vector<std::vector<int>> matrix {{1,   4,  7, 11, 15},
                                          {2,   5,  8, 12, 19},
                                          {3,   6,  9, 16, 22},
                                          {10, 13, 14, 17, 24},
                                          {18, 21, 23, 26, 30}};
    int target = 13;

    Solution sol;
    sol.findNumberIn2DArray(matrix, target);

    return 0;
}