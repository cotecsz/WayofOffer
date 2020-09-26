//
// Created by Yang Shuangzhen on 2020/9/26.
//

#include <vector>
#include <queue>
#include <stack>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

/*
 * 递归遍历二叉树。
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return root;
        std::swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
    }
};

/*
 * 利用先序遍历的迭代版本（标记法）进行遍历，遍历过程中对每个节点的左右子节点交换。
 */
class SolutionIterationMark{
public:
    TreeNode* invertTree(TreeNode* root){
        std::stack<TreeNode*> st;
        if (root != nullptr)
            st.push(root);

        while (!st.empty()){
            TreeNode* node = st.top();
            if (node != nullptr){
                st.pop();

                if (node->right)    st.push(node->right);       // 右
                if (node->left)     st.push(node->left);        // 左
                st.push(node);                                  // 中
                st.push(nullptr);
            }
            else{
                st.pop();

                node = st.top();
                st.pop();
                std::swap(node->left, node->right);
            }
        }

        return root;
    }
};

/*
 * 利用层次遍历二叉树，遍历时，交换每个节点的左右节点。
 */
class SolutionLevelTraversal{
public:
    TreeNode* invertTree(TreeNode* root){
        std::queue<TreeNode*> que;
        if (root != nullptr)
            que.push(root);

        while(!que.empty()){
            int size = que.size();
            for (int i=0; i<size; i++){
                TreeNode* node = que.front();
                que.pop();

                std::swap(node->left, node->right);

                if (node->left)     que.push(node->left);
                if (node->right)    que.push(node->right);
            }
        }

        return root;
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

    std::vector<int> res = {0, 2, 6};
    Solution sol;
    TreeNode* root = sol.invertTree(&a);

    SolutionIterationMark solIterMark;
    root = solIterMark.invertTree(&a);

    SolutionLevelTraversal solLevelTraversal;
    root = solLevelTraversal.invertTree(&a);

    return 0;
}
