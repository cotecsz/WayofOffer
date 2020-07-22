//
// Created by Yang Shuangzhen on 2020/7/22.
//

/*
 * Leetcode 376 摇摆序列
 *      摇摆序列满足
 *          1. 相邻元素的差正负交替
 *          2. 小于2个元素的序列
 *          3. 两个元素不等的序列
 *      给定一个随机序列，求这个序列满足摇摆序列的最长摇摆子序列。
 *
 *      基本思路：
 *          利用状态机进行转换。在BEGIN 两种情况，对于UP DOWN 一种判断即可。
 *
 */

#include <vector>
using namespace std;


class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2){
            return nums.size();
        }

        const int BEGIN = 0;
        const int UP = 1;
        const int DOWN = 2;
        int STATE = BEGIN;
        int maxLen = 1;

        for (int i=1; i<nums.size(); i++){
            switch(STATE){
                case BEGIN:
                    if (nums[i] > nums[i-1]){
                        STATE = UP;
                        maxLen++;
                    }
                    if (nums[i] < nums[i-1]){
                        STATE = DOWN;
                        maxLen++;
                    }
                    break;
                case UP:
                    if (nums[i] < nums[i-1]){
                        STATE = DOWN;
                        maxLen++;
                    }
                    break;
                case DOWN:
                    if(nums[i] > nums[i-1]){
                        STATE = UP;
                        maxLen++;
                    }
                    break;
            }
        }

        return maxLen;
    }
};


int main(){
    vector<int> nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};

    Solution sol;
    int len = sol.wiggleMaxLength(nums);
    assert (len == 7);

    return 0;
}
