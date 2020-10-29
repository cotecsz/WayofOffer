//
// Created by Yang Shuangzhen on 2020/10/29.
//
#include <vector>
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

/*
 * Leetcode 108 将有序数组转换为二叉搜索树
 *      基本思路：
 *         二分法：使用中间节点作为根节点，左边作为左子树，右边作为右子树
 *      Todo:
 *         迭代法
 *
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return traversal(nums, 0, nums.size()-1);
    }

    TreeNode* traversal(std::vector<int>& nums, int left, int right){
        if (left > right)   return nullptr;

        int mid = left + (right-left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = traversal(nums, left, mid-1);      // [left, mid-1]
        root->right = traversal(nums, mid+1, right);     // [mid+1, right]

        return root;
    }
};

int main(){
    std::vector<int> nums({-10,-3,0,5,9});

    Solution sol;
    TreeNode* root = sol.sortedArrayToBST(nums );
    return 0;
}