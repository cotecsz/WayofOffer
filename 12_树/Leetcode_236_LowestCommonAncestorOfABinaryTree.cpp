//
// Created by Yang Shuangzhen on 2020/10/18.
//
#include <iostream>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

/*
 * Leetcode 236 二叉树的最近公共祖先
 *     自底向下遍历二叉树，即后序遍历二叉树。
 *     使用 left 和 right 记录找到的祖先节点。
 *     1. 若left 和 right 都为空，则没有祖先
 *     2. 若left 和 right 都不为空，则left right 分别为p q的祖先，返回 root
 *     3. left 或 right 不为空，即祖先节点节点，返回不为空的节点即可
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || root == nullptr)  return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr)    return root;
        if (left == nullptr )   return right;

        return left;
    }
};

/*
 *                    a 3
 *                 /       \
 *               b 1       c 5
 *             /    \      /   \
 *           d 0    e 2   f 3  g 6
 */
int main(){
    TreeNode a(3);
    TreeNode b(1);
    TreeNode c(5);
    TreeNode d(0);
    TreeNode e(2);
    TreeNode f(3);
    TreeNode g(6);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;

    Solution sol;
    assert(sol.lowestCommonAncestor(&a, &e, &g) == &a);

    return 0;
}