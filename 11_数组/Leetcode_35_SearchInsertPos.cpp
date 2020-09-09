//
// Created by Yang Shuangzhen on 2020/9/9.
//

#include <vector>

/*
 *    Leetcode 35: 搜索插入位置
 *    基本思路：
 *       解法1：遍历数组，当 target >= nums[i] 返回i
 *       解法2: 二分查找
 *              二分查找数组中的元素，返回元素索引，若target不在数组中，二分查找结束，返回high
 */

class Solution {
public:
//    int searchInsert(std::vector<int>& nums, int target) {
//        for (int i=0; i< nums.size(); i++){
//            if (target <= nums[i])
//                return i;
//        }
//        return nums.size();
//    }
    int searchInsert(std::vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size();
        while (low < high){
            int mid = low + (high-low) / 2;
            if (target < nums[mid])         high = mid;
            else if (target == nums[mid])   return mid;
            else                            low = mid+1;
        }
        return high;
    }
};

int main(){
    std::vector<int> nums({2, 3, 5, 6, 9, 10});

    Solution sol;
    assert(sol.searchInsert(nums, 11) == 6);

    return 0;
}