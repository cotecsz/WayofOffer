//
// Created by Yang Shuangzhen on 2020/10/22.
//

#include <vector>
/*
 * Leetcode 235 二叉搜索树的最近公共祖先
 *     基本思路：二叉搜索树是有序的，自顶向下比较，根节点若是大于两个节点，则公共祖先在左侧
 *             根节点若是小于两个节点，则公共祖先在右侧
 *             若是一大一小，则为公共祖先。
 */

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        else return root;
    }
};

class SolutionIteration {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root){
            if (root->val > p->val && root->val > q->val){
                root = root->left;
            }
            else if (root->val < p->val && root->val < q->val){
                root = root->right;
            }
            else  return root;
        }
    }
};
/*
 *                    a 3
 *                 /       \
 *               b 1       c 5
 *             /    \      /   \
 *           d 0    e 2   f 4  g 6
 */
int main(){
    TreeNode a(3);
    TreeNode b(1);
    TreeNode c(5);
    TreeNode d(0);
    TreeNode e(2);
    TreeNode f(4);
    TreeNode g(6);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;

    Solution sol;
    assert(sol.lowestCommonAncestor(&a, &f, &g) == &c);

    SolutionIteration solIter;
    assert(solIter.lowestCommonAncestor(&a, &d, &e) == &b);

    return 0;
}

