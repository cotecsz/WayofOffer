//
// Created by Yang Shuangzhen on 2020/7/18.
//

#include <iostream>
#include <queue>

using namespace std;

/*
 * Leetcode 215 找数组中 第K大的数
 *     基本思路：维护一个最小堆，大小为K，保存数组前 K 大的数，堆顶为第K大数
 *
 *     时间复杂度：O(NlogK)
 *     空间复杂度：O(N)
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> smallHeap;

        for (int i=0; i < nums.size(); i++){
            if (smallHeap.size() < k)
                smallHeap.push(nums[i]);
            else if(nums[i] > smallHeap.top()){
                smallHeap.pop();
                smallHeap.push(nums[i]);
            }
        }

        return smallHeap.top();
    }
};


int main(){
    vector<int> nums = {3, 1, 4, 9, 20, 99, 100};

    Solution sol;
    assert(sol.findKthLargest(nums, 2) == 99);

    return 0;
}

