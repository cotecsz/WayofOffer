//
// Created by Yang Shuangzhen on 2020/10/10.
//

#include <vector>
#include <iostream>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

using namespace std;

class Solution {
public:
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        if (inorder.size() == 0 && postorder.size() == 0){
            return nullptr;
        }
        return traversal(inorder, 0, inorder.size(),
                postorder, 0, postorder.size());
    }

    TreeNode* traversal(std::vector<int>& inorder, int inorderBegin, int inorderEnd,
                        std::vector<int>& postorder, int postorderBegin, int postorderEnd){
        // 后序遍历序列为空
        if (postorderBegin == postorderEnd)     return nullptr;

        // 构造根节点
        int rootVal = postorder[postorderEnd-1];
        TreeNode* root = new TreeNode(rootVal);

        // 后序遍历序列仅有一个
        if (postorderEnd - postorderBegin == 1)     return root;

        int delimiterIndex;
        for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++){
            if (inorder[delimiterIndex] == rootVal){
                break;
            }
        }

        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;
        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;

        int leftPostorderBegin = postorderBegin;
        int leftPostorderEnd = postorderBegin +  delimiterIndex - inorderBegin;
        int rightPostorderBegin = postorderBegin +  delimiterIndex - inorderBegin;
        int rightPostorderEnd = postorderEnd - 1;

        root->left = traversal(inorder, leftInorderBegin, leftInorderEnd,
                postorder, leftPostorderBegin, leftPostorderEnd);
        root->right = traversal(inorder, rightInorderBegin, rightInorderEnd,
                postorder, rightPostorderBegin, rightPostorderEnd);

        return root;
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

    std::vector<int> inorder = {3, 1, 4, 0, 5, 2, 6};
    std::vector<int> postorder = {3, 4, 1, 5, 6, 2, 0};

    Solution sol;
    TreeNode* root = sol.buildTree(inorder, postorder);

    return 0;
}
