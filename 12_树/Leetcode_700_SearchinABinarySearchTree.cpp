//
// Created by Yang Shuangzhen on 2020/10/13.
//

#include <iostream>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root->val == val)    return root;

        if (val < root->val){
            return searchBST(root->left, val);
        }
        else if(val > root->val){
            return searchBST(root->right,val);
        }

        return nullptr;
    }
};

class SolutionIteration {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root->val == val)    return root;

        TreeNode* node = root;
        while (node){
            if (val < node->val){
                node = node->left;
            }
            else if (val > node->val){
                node = node->right;
            }
            else{
                return node;
            }
        }
        return nullptr;
    }
};
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

    int val = 1;
    Solution sol;
    TreeNode* node = sol.searchBST(&a, val);

    SolutionIteration solIter;
    TreeNode* nodeIter = solIter.searchBST(&a, val);

    assert(node == nodeIter);
    return 0;
}