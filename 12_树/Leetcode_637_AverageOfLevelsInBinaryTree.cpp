//
// Created by Yang Shuangzhen on 2020/9/26.
//

#include <vector>
#include <queue>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

class Solution {
public:
    std::vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double> res;
        std::queue<TreeNode*> que;
        if (root != nullptr)    que.push(root);

        while (!que.empty()){
            int size = que.size();
            double sum = 0.0;
            for (int i=0; i<size; i++){
                TreeNode* node = que.front();
                que.pop();
                sum += node->val;
                if (node->left)     que.push(node->left);
                if (node->right)    que.push(node->right);
            }

            res.push_back(sum / size);
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

    std::vector<double> res = {0, 1.5, 4.5};
    Solution sol;
    assert(sol.averageOfLevels(&a) == res);

    return 0;
}