//
// Created by Yang Shuangzhen on 2020/10/22.
//
#include <vector>
#include <queue>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

std::vector<int> levelOrder(TreeNode* root){
    std::vector<int> res;
    std::queue<TreeNode*> que;
    if (root != nullptr)
        que.push(root);

    while (!que.empty()){
        int size = que.size();
        // std::vector<int> vec;

        for (int i=0; i<size; i++){
            TreeNode* node = que.front();
            que.pop();

            res.push_back(node->val);
            if (node->left)     que.push(node->left);
            if (node->right)    que.push(node->right);
        }
        // res.push_back(vec);
    }

    return res;
}

/*
 * Leetcode 701: 二叉搜索树中的插入操作
 *     判断是否为空树，直接建立节点返回。否则，向下查找位置，若节点值大于插入节点，则在做节点寻找，否则右子树中查找。
 *
 *     迭代：双指针法。记录要插入的节点父节点。查找完成后插入即可。
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr){
            TreeNode* node = new TreeNode(val);
            return node;
        }


        if (val < root->val){
            root->left = insertIntoBST(root->left, val);
        }
        else if (val > root->val){
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};

class SolutionIteration {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr){
            TreeNode* node = new TreeNode(val);
            return node;
        }

        TreeNode* cur = root;
        TreeNode* pre = root;
        while (cur){
            pre = cur;
            if (cur->val > val){
                cur = cur->left;
            }
            if (cur->val < val){
                cur = cur->right;
            }
        }
        TreeNode* node = new TreeNode(val);
        if (pre->val > val)     pre->left = node;
        else                    pre->right = node;

        return root;
    }
};

/*
 *                    a 3
 *                 /       \
 *               b 1       c 5
 *             /    \      /   \
 *           d 0    e 2   f 4  g 6
 */
int main(){
    TreeNode a(3);
    TreeNode b(1);
    TreeNode c(5);
    TreeNode d(0);
    TreeNode e(2);
    TreeNode f(4);
    TreeNode g(6);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;

    Solution sol;
    TreeNode* root = sol.insertIntoBST(&a, 7);
    std::vector<int> res = levelOrder(root);

    SolutionIteration solIter;
    TreeNode* root1 = solIter.insertIntoBST(&a, 8);
    std::vector<int> res1 = levelOrder(root);

    return 0;
}
