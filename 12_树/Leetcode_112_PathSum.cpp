//
// Created by Yang Shuangzhen on 2020/10/9.
//

#include <stack>
#include <vector>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

class Solution {
public:
//    bool hasPathSum(TreeNode* root, int sum) {
//        if (root == nullptr)    return false;
//        if (!root->left && !root->right && sum == 0)    return true;
//
//        if (root->left){
//            if (hasPathSum(root->left, sum - root->left->val)){     // 回溯
//                return true;
//            }
//        }
//        if (root->right){
//            if (hasPathSum(root->right, sum - root->right->val)){
//                return true;
//            }
//        }
//
//        return false;
//    }
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr)     return false;

        return traversal(root, sum-root->val);

    }

    bool traversal(TreeNode* root, int sum){
        if (!root->left && !root->right && sum == 0){
            return true;
        }

        if (!root->left && !root->left){
            return false;
        }

        bool left = false;
        bool right = false;
        if (root->left)     left = traversal(root->left, sum - root->left->val);
        if (root->right)    right = traversal(root->right, sum - root->right->val);

        return left || right;
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

    std::vector<int> preorder(TreeNode* root){
        std::stack<TreeNode*> st;
        std::vector<int> res;
        if (root != nullptr)    st.push(root);

        while (!st.empty()){
            TreeNode* node = st.top();      st.pop();

            res.push_back(node->val);
            if (node->left)     st.push(node->left);
            if (node->right)     st.push(node->right);
        }
        std::reverse(res.begin(), res.end());
        return res;
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
//    assert(sol.hasPathSum(&a, 5));

    SolutionIterationPreorder solPreodr;
    assert(solPreodr.hasPathSum(&a, 5));

    solPreodr.preorder(&a);

    TreeNode m(-3);
    TreeNode n(-2);
    m.right = &a;

    assert(sol.hasPathSum(&m, -5));

    return 0;
}
