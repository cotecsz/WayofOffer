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
    int minDepth(TreeNode* root) {
        if (root == nullptr)    return 0;
        if (root->left == nullptr && root->right != nullptr){
            return 1 + minDepth(root->right);
        }
        if (root->right == nullptr && root->left != nullptr){
            return 1 + minDepth(root->left);
        }

        return  1 + std::min(minDepth(root->left), minDepth(root->right));
    }
};

class SolutionIterationLevelTraversal {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)    return 0;
        int depth = 0;
        std::queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()){
            int size = que.size();
            ++depth;
            bool flag = false;
            for (int i=0; i<size; i++){
                TreeNode* node = que.front();
                que.pop();

                if (node->left)     que.push(node->left);
                if (node->right)    que.push(node->right);
                if (!node->left && !node->right){
                    flag = true;
                    break;
                }
            }
            if (flag){
                break;
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
    assert(sol.minDepth(&a) == 3);

    SolutionIterationLevelTraversal solIterLevelTraversal;
    assert(solIterLevelTraversal.minDepth(&a) == 3);

    return 0;
}
