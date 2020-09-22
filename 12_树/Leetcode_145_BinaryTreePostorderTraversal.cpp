//
// Created by Yang Shuangzhen on 2020/9/22.
//

#include <vector>
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

class Solution{
public:
    std::vector<int> postorderTraversal(TreeNode* root){
        std::vector<int> res;
        traversal(root, res);

        return res;
    }

    void traversal(TreeNode* root, std::vector<int>& res){
        if (root == nullptr)
            return ;

        traversal(root->left, res);
        traversal(root->right, res);
        res.push_back(root->val);
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

    std::vector<int> res = {3, 4, 1, 5, 6, 2, 0};
    Solution sol;
    assert(sol.postorderTraversal(&a) == res );
}