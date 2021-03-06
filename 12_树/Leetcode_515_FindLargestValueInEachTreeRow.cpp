//
// Created by Yang Shuangzhen on 2020/9/26.
//

#include <vector>
#include <queue>
#include <climits>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

class Solution {
public:
    std::vector<int> largestValues(TreeNode* root) {
        std::vector<int> res;
        std::queue<TreeNode*> que;
        if (root != nullptr)    que.push(root);

        while (!que.empty()){
            int size = que.size();
            int maxNum = INT_MIN;
            for (int i=0; i<size; i++){
                TreeNode* node = que.front();
                que.pop();

                if (node->val > maxNum)     maxNum = node->val;
                if (node->left)     que.push(node->left);
                if (node->right)    que.push(node->right);
            }
            res.push_back(maxNum);
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

    std::vector<int> res = {0, 2, 6};
    Solution sol;
    assert(sol.largestValues(&a) == res);

    return 0;
}