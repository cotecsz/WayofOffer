//
// Created by Yang Shuangzhen on 2020/10/10.
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
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        if (preorder.size() == 0 && inorder.size() == 0){
            return nullptr;
        }

        return traversal(preorder, 0, preorder.size(),
                inorder, 0, inorder.size());
    }

    TreeNode* traversal(std::vector<int>& preorder, int preorderBegin, int preorderEnd,
            std::vector<int>& inorder, int inorderBegin, int inorderEnd){
        if (preorderBegin == preorderEnd)       return nullptr;

        int rootVal = preorder[preorderBegin];
        TreeNode* root = new TreeNode(rootVal);
        
        if (preorderEnd - preorderBegin == 1)       return root;
        
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
        
        int leftPreorderBegin = preorderBegin + 1;
        int leftPreorderEnd = preorderBegin + 1 + delimiterIndex - inorderBegin;
        int rightPreorderBegin = preorderBegin + 1 + delimiterIndex - inorderBegin;
        int rightPreorderEnd = preorderEnd;
        
        root->left = traversal(preorder, leftPreorderBegin, leftPreorderEnd,
                inorder, leftInorderBegin, leftInorderEnd);
        root->right = traversal(preorder, rightPreorderBegin, rightPreorderEnd,
                inorder, rightInorderBegin, rightInorderEnd);
        
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
    std::vector<int> preorder = {0, 1, 3, 4, 2, 5, 6};

    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);

    return 0;
}
