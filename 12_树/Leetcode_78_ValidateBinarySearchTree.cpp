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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)    return true;

        for (int i=0; i<vec.size(); i++){
            if (vec[i] > vec[i+1]){
                return false;
            }
        }

        return true;
    }

private:
    std::vector<int> vec;

    void traversal(TreeNode* root){
         vec.clear();
         if (root == nullptr)    return ;

        traversal(root->left);
        vec.push_back(root->val);
        traversal(root->right);

        return ;
    }
};

/*
 * 递归中比较大小，无需额外空间
 */
class SolutionNOExtSpace {
public:
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)    return true;

        bool left = isValidBST(root->left);
        if (pre != nullptr && pre->val > root->val){
            return false;
        }
        pre = root;

        bool right = isValidBST(root->right);

        return left && right;
    }
};

/*
 * 中序遍历
 */
class SolutionInorderTraversal {
public:
    bool isValidBST(TreeNode* root) {
        std::stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;

        while (cur != nullptr || !st.empty()){
            if (cur != nullptr){
                st.push(cur);
                cur = cur->left;        // 左
            }
            else{
                cur = st.top();         // 中
                st.pop();

                if (pre != nullptr && pre->val > cur->val){
                    return false;
                }
                pre = cur;

                cur = cur->right;       // 右
            }
        }

        return true;
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
    assert(sol.isValidBST(&a));

    SolutionNOExtSpace solNoExtSpa;
    assert(solNoExtSpa.isValidBST(&a));

    SolutionInorderTraversal solInorTrav;
    assert(solInorTrav.isValidBST(&a));

    return 0;
}