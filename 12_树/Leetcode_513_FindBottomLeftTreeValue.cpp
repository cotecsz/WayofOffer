//
// Created by Yang Shuangzhen on 2020/10/7.
//

#include <queue>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

class SolutionIterationLevelTraversal {
public:
    int findBottomLeftValue(TreeNode *root) {
        std::queue<TreeNode*> que;
        if (root == nullptr)    return 0;
        que.push(root);

        int res = 0;
        while (!que.empty()){
            int size = que.size();

            for (int i=0; i<size; i++){
                TreeNode* node = que.front();
                que.pop();
                if (i == 0)     res = node->val;

                if (node->left)     que.push(node->left);
                if (node->right)    que.push(node->right);
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

    // Solution sol;
    // assert(sol.sumOfLeftLeaves(&a) == 8);

    SolutionIterationLevelTraversal solIterLevelTrvs;
    assert(solIterLevelTrvs.findBottomLeftValue(&a) == 3);

    return 0;
}