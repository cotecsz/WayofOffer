//
// Created by Yang Shuangzhen on 2020/9/22.
//

#include <vector>
#include <stack>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

class Solution{
public:
    std::vector<int> preorderTraversal(TreeNode* root){
        std::vector<int> res;
        traversal(root, res);

        return res;
    }

    void traversal(TreeNode* root, std::vector<int> &res){
        if (root == nullptr)
            return ;
        res.push_back(root->val);
        traversal(root->left, res);
        traversal(root->right, res);
    }
};

/*
 * 二叉树的先序遍历（根左右）
 *      基本思路：利用栈遍历，依次取栈顶元素，出栈顺序应为根左右。
 *      出入栈顺序：根入栈，根出栈，右子树入栈，左子树入栈，左子树出栈，右子树出栈。
 */
class SolutionIteration{
public:
    std::vector<int> preorderTraversal(TreeNode* root){
        std::vector<int> res;
        std::stack<TreeNode* > st;
        st.push(root);                  // 根
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            if (node != nullptr)    res.push_back(node->val);
            else continue;
            st.push(node->right);       // 右
            st.push(node->left);        // 左
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

    std::vector<int> res = {0, 1, 3, 4, 2, 5, 6};

    // 递归版本
    Solution sol;
    assert(sol.preorderTraversal(&a) == res );

    // 迭代版本
    SolutionIteration solIter;
    assert(solIter.preorderTraversal(&a) == res);

    return 0;
}

