//
// Created by Yang Shuangzhen on 2020/10/3.
//
#include <queue>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return getDepth(root);
    }

    int getDepth(TreeNode* node){
        if (node == nullptr)    return 0;

        // 左子树深度
        int leftDepth = getDepth(node->left);
        if (leftDepth == -1)    return -1;
        // 右子树深度
        int rightDepth = getDepth(node->right);
        if (rightDepth == -1)   return -1;

        // 如果深度差超过1 则返回-1，否则返回较高的深度
        return std::abs(leftDepth - rightDepth) > 1 ? -1 : 1+std::max(leftDepth, rightDepth);
    }
};

int main(){
    TreeNode a(0);
    TreeNode b(1);
    TreeNode c(2);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(5);
    TreeNode g(6);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;

    Solution sol;
    assert(sol.isBalanced(&a));


    return 0;
}
