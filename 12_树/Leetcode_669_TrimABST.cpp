//
// Created by Yang Shuangzhen on 2020/10/22.
//

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr)    return root;

        if (root->val < low)    return trimBST(root->right, low, high); // 节点值小于最小值，返回右子树
        if (root->val > high)   return trimBST(root->left, low, high);  // 节点值大于最大值，返回左子树

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

class SolutionIteration {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr)    return root;

        // root 为区间[low, high] 范围之内
        while (root->val < low || root->val > high){
            if (root->val < low)    root = root->right;
            else                    root = root->left;
        }

        // 左节点小于最小值，则将左节点的右子树作为左节点
        TreeNode* cur = root;
        while (cur != nullptr){
            while (cur->left && cur->left->val < low){      // while
                cur->left = cur->left->right;
            }
            cur = cur->left;
        }

        // 右节点大于最大值，则将右节点的左子树作为右节点
        cur = root;
        while (cur != nullptr){
            while (cur->right && cur->right->val > high){
                cur->right = cur->right->left;
            }
            cur = cur->right;
        }

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
    // TreeNode* root = sol.trimBST(&a, 1, 6);

    SolutionIteration solIter;
    TreeNode* rootIter = solIter.trimBST(&a, 3, 6);

    return 0;
}