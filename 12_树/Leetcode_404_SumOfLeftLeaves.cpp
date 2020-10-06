//
// Created by Yang Shuangzhen on 2020/10/6.
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }

        int leftValue = sumOfLeftLeaves(root->left);
        int rightValue = sumOfLeftLeaves(root->right);

        int midValue = 0;
        // 左叶子节点判定：左孩子不为空，但左孩子的左右孩子都为空，即所有为叶节点的左孩子
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
        {
            midValue = root->left->val;
        }

        return midValue + leftValue + rightValue;
    }
};

class SolutionIterationPostOrder{
public:
    int sumOfLeftLeaves(TreeNode* root){
        std::stack<TreeNode*> st;
        if (root == nullptr){
            return 0;
        }

        st.push(root);
        int res = 0;
        while (!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            if (node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr)
            {
                res += node->left->val;
            }

            if (node->right)    st.push(node->right);
            if (node->left)     st.push(node->left);
        }

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
    assert(sol.sumOfLeftLeaves(&a) == 8);

    SolutionIterationPostOrder solIterPostOrder;
    assert(solIterPostOrder.sumOfLeftLeaves(&a) == 8);

    return 0;
}