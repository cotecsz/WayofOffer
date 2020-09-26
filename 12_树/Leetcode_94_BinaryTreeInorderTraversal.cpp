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
    std::vector<int> inorderTraversal(TreeNode* root){
        std::vector<int> res;
        traversal(root, res);

        return res;
    }

    void traversal(TreeNode* root, std::vector<int>& res){
        if (root == nullptr)
            return ;

        traversal(root->left, res);
        res.push_back(root->val);
        traversal(root->right, res);
    }
};

/*
 * 中序遍历迭代版本：
 *      基本思路：利用指针和栈遍历二叉树。
 */
class SolutionIteration{
public:
    std::vector<int> inorderTraversal(TreeNode* root){
        std::vector<int> res;
        std::stack<TreeNode*> st;
        TreeNode* curr = root;

        while (!st.empty() || curr != nullptr){
            if (curr != nullptr){
                st.push(curr);
                curr = curr->left;          // 左
            }
            else{
                curr = st.top();
                st.pop();
                res.push_back(curr->val);   // 中

                curr = curr->right;         // 右
            }
        }

        return res;
    }
};

/*
 * 中序遍历统一迭代方式：标记法
 */
class SolutionIterationMark{
public:
    std::vector<int> inorderTraversal(TreeNode* root){
        std::vector<int> res;
        std::stack<TreeNode*> st;
        if (root != nullptr)    st.push(root);

        while (!st.empty()){
            TreeNode* node = st.top();
            if (node != nullptr){
                st.pop();

                if (node->right)    st.push(node->right);       // 右
                st.push(node);      st.push(nullptr);        // 中， 标记

                if (node->left)     st.push(node->left);        // 左
            }
            else{
                st.pop();
                node = st.top();
                st.pop();

                res.push_back(node->val);
            }
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

    std::vector<int> res = {3, 1, 4, 0, 5, 2, 6};
    Solution sol;
    assert(sol.inorderTraversal(&a) == res );

    SolutionIteration solIter;
    assert(solIter.inorderTraversal(&a) == res);

    SolutionIterationMark solIterMark;
    assert(solIterMark.inorderTraversal(&a) == res);
    return 0;
}
