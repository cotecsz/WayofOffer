//
// Created by Yang Shuangzhen on 2020/10/16.
//

#include <vector>
#include <stack>
#include <iostream>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vec.clear();
        traversal(root);
        if (vec.size() < 2)     return 0;

        int res = INT_MAX;
        for (int i=1; i<vec.size(); i++){
            res = std::min(vec[i]-vec[i-1], res);       // BST 有序，所以后一个数必然大于前一个数
        }
        return res;
    }

private:
    std::vector<int> vec;
    void traversal(TreeNode* root){
        if (root == nullptr)    return ;

        traversal(root->left);
        vec.push_back(root->val);
        traversal(root->right);

        return  ;
    }
};

class SolutionNOExtSpace {
public:
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr)    return 0;
        traversal(root);
        return res;
    }
private:
    int res = INT_MAX;
    TreeNode* pre = nullptr;
    void traversal(TreeNode* root){
        if (root == nullptr)    return ;

        traversal(root->left);      // 左
        if (pre != nullptr){
            res = std::min(root->val - pre->val, res);
        }
        pre = root;                 // 中
        traversal(root->right);     // 右
    }
};

class SolutionInorderTraversal {
public:
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr)    return 0;

        std::stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        int res = INT_MAX;
        while (cur != nullptr || !st.empty()){
            if (cur != nullptr){
                st.push(cur);
                cur = cur->left;
            }
            else{
                cur = st.top();
                st.pop();

                if (pre != nullptr){
                    res = std::min(cur->val - pre->val, res);
                }
                pre = cur;
                cur = cur->right;
            }
        }
        return res;
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

    Solution sol;
    assert(sol.getMinimumDifference(&a) == 1);

    SolutionNOExtSpace solNoExtSpace;
    assert(solNoExtSpace.getMinimumDifference(&a) == 1);

    SolutionInorderTraversal solInordTrav;
    assert(solInordTrav.getMinimumDifference(&a) == 1);
    return 0;
}