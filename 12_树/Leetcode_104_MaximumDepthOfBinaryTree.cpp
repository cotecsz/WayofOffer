//
// Created by Yang Shuangzhen on 2020/9/29.
//

#include <queue>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)    return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return 1 + std::max(leftDepth, rightDepth);
    }
};

class SolutionIterationQueue{
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)    return 0;

        int depth = 0;
        std::queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()){
            int size = que.size();
            ++depth;

            for (int i=0; i<size; i++){
                TreeNode* node = que.front();   que.pop();

                if (node->left)     que.push(node->left);
                if (node->right)    que.push(node->right);
            }
        }

        return depth;
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
    assert(sol.maxDepth(&a) == 3);

    SolutionIterationQueue solIterQueue;
    assert(sol.maxDepth(&a) == 3);
    
    return 0;
}

