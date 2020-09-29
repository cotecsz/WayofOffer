//
// Created by Yang Shuangzhen on 2020/9/29.
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


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return false;
        else
            return compare(root->left, root->right);
    }

    bool compare(TreeNode* left, TreeNode* right){
        if (left != nullptr && right == nullptr)    return false;
        else if (left == nullptr && right != nullptr)   return false;
        else if (left == nullptr && right == nullptr)   return true;
        else if (left->val != right->val)               return false;

        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        return outside && inside;
    }
};

class SolutionItrerationStack {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)    return false;
        std::stack<TreeNode*> st;
        st.push(root->right);
        st.push(root->left);

        while (!st.empty()){
            TreeNode* leftNode = st.top();  st.pop();
            TreeNode* rightNode = st.top(); st.pop();

            if (!leftNode && !rightNode) continue;
            if (leftNode == nullptr || rightNode == nullptr || (leftNode->val != rightNode->val))
                return false;

            st.push(leftNode->left);
            st.push(rightNode->right);
            st.push(leftNode->right);
            st.push(rightNode->left);
        }

        return true;
    }
};

class SolutionItrerationQueue {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)    return false;
        std::queue<TreeNode*> que;
        que.push(root->right);
        que.push(root->left);

        while (!que.empty()){
            TreeNode* leftNode = que.front();  que.pop();
            TreeNode* rightNode = que.front(); que.pop();

            if (!leftNode && !rightNode) continue;
            if (leftNode == nullptr || rightNode == nullptr || (leftNode->val != rightNode->val))
                return false;

            que.push(leftNode->left);
            que.push(rightNode->right);
            que.push(leftNode->right);
            que.push(rightNode->left);
        }

        return true;
    }
};
int main(){
    TreeNode a(0);
    TreeNode b(1);
    TreeNode c(1);
    TreeNode d(2);
    TreeNode e(3);
    TreeNode f(3);
    TreeNode g(2);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;

    Solution sol;
    assert(sol.isSymmetric(&a));

    SolutionItrerationStack solIterStack;
    assert(solIterStack.isSymmetric(&a));

    SolutionItrerationQueue solIterQueue;
    assert(solIterQueue.isSymmetric(&a));

    return 0;
}