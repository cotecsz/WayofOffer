//
// Created by Yang Shuangzhen on 2020/10/29.
//

#include <vector>

/*
 * Leetcode 654: 最大二叉树
 *     基本思路：
 *        1. 数组中最大值为作为 根节点
 *        2. 最大值左边 为左子树
 *        3. 最大值右边 为右子树
 *        通过前序遍历构建二叉树
 */
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }

    TreeNode* traversal(std::vector<int>& nums, int left, int right){
        if (left >= right)   return nullptr;

        int maxIndex = left;
        for (int i=left+1; i < right; i++){
            if (nums[maxIndex] < nums[i]){
                maxIndex = i;
            }
        }

        TreeNode* root = new TreeNode(nums[maxIndex]);
        root->left = traversal(nums, left, maxIndex);           // [left, maxIndex)
        root->right = traversal(nums, maxIndex+1, right);   // [maxIndex+1, right)

        return root;
    }
};
int main(){
    std::vector<int> nums({3,2,1,6,0,5});

    Solution sol;
    TreeNode* root = sol.constructMaximumBinaryTree(nums );
    return 0;
}