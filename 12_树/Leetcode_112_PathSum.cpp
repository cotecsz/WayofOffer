//
// Created by Yang Shuangzhen on 2020/10/9.
//

#include <stack>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr)    return false;
        if (!root->left && !root->right && sum == 0)    return true;

        if (root->left){
            if (hasPathSum(root->left, sum - root->left->val)){     // 回溯
                return true;
            }
        }
        if (root->right){
            if (hasPathSum(root->right, sum - root->right->val)){
                return true;
            }
        }

        return false;
    }
};

class SolutionIterationPreorder {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        std::stack<std::pair<TreeNode*, int>> st;
        st.push(std::pair<TreeNode*, int>(root, root->val));

        while (!st.empty()){
            std::pair<TreeNode*, int> node = st.top();
            st.pop();

            if (!node.first->left && !node.first->right && sum == node.second)      return true;
            if (node.first->right){
                st.push(std::pair<TreeNode*, int>(node.first->right, node.second + node.first->right->val));
            }
            if (node.first->left){
                st.push(std::pair<TreeNode*, int>(node.first->left, node.second + node.first->left->val));
            }
        }

        return false;
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
    assert(sol.hasPathSum(&a, 5));

    SolutionIterationPreorder solPreodr;
    assert(solPreodr.hasPathSum(&a, 5));

    return 0;
}
