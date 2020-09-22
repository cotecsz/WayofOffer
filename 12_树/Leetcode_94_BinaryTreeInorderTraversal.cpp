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
    std::vector<int> inorderTraversal(TreeNode* root){
        std::vector<int> res;
        traversal(root, res);

        return res;
    }

    void traversal(TreeNode* root, std::vector<int>& res){
        if (root == nullptr)
            return ;

        traversal(root->left, res);
        res.push_back(root->val);
        traversal(root->right, res);
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

    std::vector<int> res = {3, 1, 4, 0, 5, 2, 6};
    Solution sol;
    assert(sol.inorderTraversal(&a) == res );
}
