//
// Created by Yang Shuangzhen on 2020/10/13.
//

#include <queue>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

class Solution {
public:
    TreeNode* mergeTreesPreorder(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr)  return t2;
        if (t2 == nullptr)  return t1;

        t1->val += t2->val;                                     // 中
        t1->left = mergeTreesPreorder(t1->left, t2->left);      // 左
        t1->right = mergeTreesPreorder(t1->right, t2->right);   // 右

        return t1;
    }
    TreeNode* mergeTreesInorder(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr)  return t2;
        if (t2 == nullptr)  return t1;

        t1->left = mergeTreesInorder(t1->left, t2->left);      // 左
        t1->val += t2->val;                                     // 中
        t1->right = mergeTreesInorder(t1->right, t2->right);   // 右

        return t1;
    }

    TreeNode* mergeTreesPostorder(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr)  return t2;
        if (t2 == nullptr)  return t1;

        t1->left = mergeTreesPostorder(t1->left, t2->left);      // 左
        t1->right = mergeTreesPostorder(t1->right, t2->right);   // 右
        t1->val += t2->val;                                      // 中

        return t1;
    }
};

class SolutionIterationLevelTraversal {
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        if (t1 == nullptr)  return t2;
        if (t2 == nullptr)  return t1;

        std::queue<TreeNode*> que;
        que.push(t1);
        que.push(t2);
        while (!que.empty()){
            TreeNode* lNode = que.front();  que.pop();
            TreeNode* rNode = que.front();  que.pop();
            lNode->val += rNode->val;

            if (lNode->left != nullptr && rNode->left != nullptr){
                que.push(lNode->left);
                que.push(rNode->left);
            }
            if (lNode->right != nullptr && rNode->right != nullptr){
                que.push(lNode->right);
                que.push(rNode->right);
            }
            if (lNode->left == nullptr && rNode->left != nullptr){
                lNode->left = rNode->left;
            }
            if (lNode->right == nullptr && rNode->right != nullptr){
                lNode->right = rNode->right;
            }
        }

        return t1;
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

    Solution sol;
    TreeNode* root = sol.mergeTreesInorder(&a, &a);

    assert(sol.mergeTreesPreorder(&a, &a) == sol.mergeTreesInorder(&a, &a) );
    assert(sol.mergeTreesInorder(&a, &a) == sol.mergeTreesPostorder(&a, &a));

    SolutionIterationLevelTraversal solIterLevTrv;
    assert(solIterLevTrv.mergeTrees(&a, &a) == sol.mergeTreesPreorder(&a, &a));
    return 0;
}

