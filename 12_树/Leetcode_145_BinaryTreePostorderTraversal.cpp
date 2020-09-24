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
    std::vector<int> postorderTraversal(TreeNode* root){
        std::vector<int> res;
        traversal(root, res);

        return res;
    }

    void traversal(TreeNode* root, std::vector<int>& res){
        if (root == nullptr)
            return ;

        traversal(root->left, res);
        traversal(root->right, res);
        res.push_back(root->val);
    }
};

/*
 * 二叉树后序遍历迭代版：
 *      利用先序遍历的迭代版，反转即可。
 */
class SolutionIteration{
public:
    std::vector<int> postorderTraversal(TreeNode* root){
        std::vector<int> res;
        std::stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            if (node != nullptr)    res.push_back(node->val);
            else continue;
            st.push(node->left);        //
            st.push(node->right);
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

    std::vector<int> res = {3, 4, 1, 5, 6, 2, 0};
    Solution sol;
    assert(sol.postorderTraversal(&a) == res );

    SolutionIteration solIter;
    assert(solIter.postorderTraversal(&a) == res);

    return 0;
}