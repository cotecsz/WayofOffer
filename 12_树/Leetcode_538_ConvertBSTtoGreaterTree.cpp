//
// Created by Yang Shuangzhen on 2020/10/29.
//

#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * Leetcode 538 将二叉搜索树转换为累加树
 *     二叉搜索树中序遍历有序 [1, 2, 3, 4] ---> [7, 9, 4, 10]
 *     基本思路：使用双指针，pre记录cur节点的前一个节点，使用右中左遍历方式，累加
 */
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        traversal(root);
        return root;
    }
private:
    int pre;
    void traversal(TreeNode* cur){
        if (cur == nullptr)     return ;

        traversal(cur->right);
        cur->val += pre;
        pre = cur->val;
        traversal(cur->left);
    }
};

class SolutionIteration {
public:
    TreeNode* convertBST(TreeNode* root) {
        pre = 0;
        traversal(root);
        return root;
    }

private:
    int pre;
    void traversal(TreeNode* root){
        std::stack<TreeNode*> st;
        TreeNode* cur = root;

        while (cur != nullptr || !st.empty()){
            if (cur != nullptr){
                st.push(cur);
                cur = cur->right;       // 右
            }
            else{
                cur = st.top();
                st.pop();
                cur->val += pre;        // 中
                pre = cur->val;
                cur = cur->left;        // 左
            }
        }
    }
};

int main(){
    TreeNode a(3);
    TreeNode b(2);
    TreeNode c(4);
    TreeNode d(1);

    a.left = &b;
    a.right = &c;
    b.left = &d;

//    Solution sol;
//    TreeNode* root = sol.convertBST(&a);

    SolutionIteration solIter;
    TreeNode* root = solIter.convertBST(&a);

    return 0;
}