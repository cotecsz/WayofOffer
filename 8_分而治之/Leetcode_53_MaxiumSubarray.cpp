//
// Created by Yang Shuangzhen on 2020/8/7.
//

#include <vector>

using std::vector;

/*
 * Leetcode 53: 求出数组的最大子数组和
 * 分而治之：
 *      1. 分解原问题：将数组分为子数组
 *      2. 递归求解子问题
 *      3. 合并子问题
 *         该问题与归并排序不同，在求的左侧数组最大值 S1 和 右侧数组最大值 S2 时，还得求出跨越两侧的子数组的最大值S3，
 *         S3 必须为左侧数组最后一个元素mid作为结尾，右侧数组第一个元素mid+1作为开头
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        result = maxSubArrayHelper(nums, 0, nums.size()-1);
        return  result;
    }

    int maxSubArrayHelper(vector<int>& nums, int left, int right){
        if (left == right){
            return nums[left];
        }

        int mid = (left + right) / 2;
        int leftSum = maxSubArrayHelper(nums, left, mid);
        int midSum = maxCrossingSubarray(nums, left, mid, right);
        int rightSum = maxSubArrayHelper(nums, mid+1, right);

        int result = std::max(leftSum, rightSum);
        result = std::max(result, midSum);

        return result;
    }

    int maxCrossingSubarray(vector<int>& nums, int left, int mid, int right){
        int leftSum = INT_MIN;
        int sum = 0;
        for (int i=mid; i >= left; i--){
            sum += nums[i];
            leftSum = std::max(sum, leftSum);
        }

        int rightSum = INT_MIN;
        sum = 0;
        for (int i=mid+1; i<=right; i++){
            sum += nums[i];
            rightSum = std::max(sum, rightSum);
        }

        return leftSum+rightSum;
    }
};

int main(){
    vector<int> nums{1, -2, 4, 5, -2, 8, 3, -2, 6, 3, 7, -1};

    Solution sol;
    int result = sol.maxSubArray(nums);
    assert(result == 32);

    return 0;
}