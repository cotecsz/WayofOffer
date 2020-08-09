//
// Created by Yang Shuangzhen on 2020/8/8.
//

#include <vector>
#include <iostream>
using std::vector;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return reversePairsHelper(nums, 0, nums.size()-1);
    }

    int reversePairsHelper(vector<int>& nums, int left, int right){
        if (left == right){
            return 0;
        }

        int mid = (left + right) / 2;
        int n_left = reversePairsHelper(nums, left, mid);
        int n_right = reversePairsHelper(nums, mid+1, right);
        int n_crossingReversePairs = crossingReversePairs(nums, left, mid, right);

        int result = n_left + n_right + n_crossingReversePairs;

        return result;
    }

    int crossingReversePairs(vector<int>& nums, int left, int mid, int right){
        vector<int> L;
        vector<int> R;

        int n1 = mid - left + 1;
        int n2 = right - mid;
        for (int i=0; i < n1; i++){
            L.push_back(nums[left+i]);
        }
        for (int j=0; j< n2; j++){
            R.push_back(nums[mid+1+j]);
        }

        int i=0, j=0, k=left, sum=0;
        while (i<L.size() && j<R.size()){
            if (L[i] <= R[j]){
                nums[k++] = L[i++];
            }
            else{
                nums[k++] = R[j++];
                sum += (L.size() - i);
            }
        }

        while (i<L.size()){
            nums[k++] = L[i++];
        }
        while (j < R.size()){
            nums[k++] = R[j++];
        }

        return sum;
    }
};

int main(){
    vector<int> nums{13, 8, 10, 6, 15, 18, 12, 20, 9, 14, 17, 19};

    Solution sol;
    int n_reversePairs = sol.reversePairs(nums);

    std::cout << n_reversePairs;
    assert(n_reversePairs == 20);
    return 0;
}