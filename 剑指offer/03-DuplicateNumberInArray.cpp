//
// Created by Yang Shuangzhen on 2020/10/21.
//

/*
 * 03-找出数组中重复数字
 *      方法1：将对应元素放入数组中索引对应的位置，当索引对应位置与元素相等，则表明元素重复
 *
 * 要求不改变元素位置
 *      二分法进行比较
 */

#include <vector>

class Solution {
public:
    int findRepeatNumber(std::vector<int>& nums) {
        if (nums.size() == 0 )  return -1;

        for (int i=0; i<nums.size(); i++){
            while (i != nums[i]){
                if (nums[i] == nums[nums[i]]){
                    return nums[i];
                }
                std::swap(nums[i], nums[nums[i]]);
            }
        }

        return -1;
    }
};

class SolutionBinarySearch {
public:
    int findRepeatNumber(std::vector<int>& nums) {
        if (nums.size() == 0)   return -1;

        int start = 0;
        int end = nums.size()-1;
        while (end >= start){
            int middle = ((end-start) >> 1) + start;
            int count = countRange(nums, start, middle);
            if (end == start){
                if (count > 1)  return start;
                else            break;
            }

            if (count > (middle-start+1)){
                end = middle;
            }
            else{
                start = middle+1;
            }
        }

        return -1;
    }

    int countRange(std::vector<int>& nums, int start, int end){
        if (nums.size() == 0){
            return 0;
        }

        int count = 0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] >= start && nums[i] <= end){
                count++;
            }
        }
        return count;
    }
};

int main(){
    std::vector<int> nums{2, 3, 1, 0, 2, 5, 3};

    Solution sol;
    assert(sol.findRepeatNumber(nums) == 2 || sol.findRepeatNumber(nums) == 3);

    SolutionBinarySearch solBinSearch;
    assert(solBinSearch.findRepeatNumber(nums) == 2 || sol.findRepeatNumber(nums) == 3);
    return 0;
}