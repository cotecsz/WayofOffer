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
 * Leetcode450: 二叉搜索树中删除节点
 *     二叉搜索树中删除节点的5中情况
 *     1. 没找到删除节点，直接返回根节点
 *
 *     2. 删除节点的左右孩子都为空，直接删除该节点
 *     3. 删除节点的左孩子为空，返回右子树
 *     4. 删除节点的右孩子为空，返回左子树
 *     5. 删除节点的左右孩子都不为空，进行调整：
 *           将要删除节点的左子树，作为右子树最最左边的节点的左孩子
 *           将要删除节点的右子树作为根节点，返回root
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr){
            return root;        // case1: 没有找到要删除的节点，则直接返回根节点。
        }

        if (root->val == key){
            // case2: 要删除的节点，左右子树都为空，则直接删除

            if (root->left == nullptr)      return root->right; // case3: 要删除的节点，左子树为空，返回右子树
            else if (root->right == nullptr)     return root->left;  // case4: 要删除的节点，右子树为空，返回左子树
            else{
                // case5： 要删除节点的左右子树都不为都不为空
                TreeNode* cur = root->right;
                while (cur->left != nullptr){
                    cur = cur->left;
                }
                cur->left = root->left;     // 1. 将左子树作为右子树最左边节点的左子树
                // TreeNode* tmp = root;       // 2. 将右子树作为根节点返回
                root = root->right;
                // delete tmp;                 // 3. 删除节点

                return root;
            }
        }

        if (root->val > key)    root->left = deleteNode(root->left, key);
        if (root->val < key)    root->right = deleteNode(root->right, key);
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
    TreeNode* root = sol.deleteNode(&a, 5);
    std::vector<int> res = levelOrder(root);

    return 0;
}