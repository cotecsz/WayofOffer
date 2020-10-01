//
// Created by Yang Shuangzhen on 2020/10/1.
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
    int countNodes(TreeNode* root) {
        if (root == nullptr)    return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

class SolutionLevelTraversal{
public:
    int countNodes(TreeNode* root){
        if (root == nullptr)    return 0;
        int numNodes = 0;
        std::queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()){
            int size = que.size();
            for (int i=0; i<que.size(); i++){
                TreeNode* node = que.front();
                que.pop();
                ++numNodes;

                if (node->left)     que.push(node->left);
                if (node->right)    que.push(node->right);
            }
        }

        return numNodes;
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
    assert(sol.countNodes(&a) == 7);

    SolutionLevelTraversal solIterLevelTraversal;
    assert(solIterLevelTraversal.countNodes(&a) == 7);

    return 0;
}

