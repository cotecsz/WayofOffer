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
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int>> res;
        std::queue<TreeNode*> que;
        if (root != nullptr)    que.push(root);

        while (!que.empty()){
            int size = que.size();
            std::vector<int> vec;

            for (int i=0; i<size; i++){
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);

                if (node->left)     que.push(node->left);
                if (node->right)    que.push(node->right);
            }

            res.push_back(vec);
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

    std::vector<std::vector<int>> res = {{3, 4, 5, 6},
                                         {1, 2},
                                         {0}};
    Solution sol;
    assert(sol.levelOrderBottom(&a) == res);

    return 0;
}
