//
// Created by Yang Shuangzhen on 2020/9/9.
//

#include <vector>

/*
 * Leetcode 27: 移除元素
 *      双指针法：遍历数组，将快指针指向的元素（非val）赋值慢指针指向的元素
 *              快指针遍历完成，返回慢指针即为新数组长度
 */

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex=0; fastIndex < nums.size(); slowIndex++, fastIndex++){
            if (nums[fastIndex] != val){
                nums[slowIndex] = nums[fastIndex];
            }
            fastIndex++;
        }
        return slowIndex;
    }
};


int main(){
    std::vector<int> nums({2, 3, 3, 2});

    Solution sol;
    assert(sol.removeElement(nums, 2) == 2);
    return 0;
}