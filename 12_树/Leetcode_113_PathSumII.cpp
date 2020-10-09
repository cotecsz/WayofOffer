//
// Created by Yang Shuangzhen on 2020/10/9.
//

#include <vector>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

class Solution {
public:
    void traversal(TreeNode* curr, int count){
        if (!curr->left && !curr->right && count == 0){
            res.push_back(path);
            return;
        }

        if (!curr->left && !curr->right)    return;

        if (curr->left){
            path.push_back(curr->left->val);
            traversal(curr->left, count - curr->left->val);
            path.pop_back();
        }

        if (curr->right){
            path.push_back(curr->right->val);
            traversal(curr->right, count - curr->right->val);
            path.pop_back();
        }

    }

    std::vector<std::vector<int>> PathSum(TreeNode* root, int sum) {
        if (root == nullptr)    return res;
        path.push_back(root->val);
        traversal(root, sum - root->val);

        return res;
    }

private:
    std::vector<std::vector<int>> res;
    std::vector<int> path;
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

    std::vector<std::vector<int>> res = {{0, 1, 4}};
    Solution sol;
    assert(sol.PathSum(&a, 5) == res);

    return 0;
}
