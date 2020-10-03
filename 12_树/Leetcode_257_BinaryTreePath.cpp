//
// Created by Yang Shuangzhen on 2020/10/3.
//
#include <vector>
#include <string>
#include <stack>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};


class Solution {
public:
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> res;
        std::string path;
        traversal(root, path, res);

        return res;
    }

    // path 未传引用类型，隐含回溯含义
    void traversal(TreeNode* node, std::string path, std::vector<std::string>& res){
        path += std::to_string(node->val);
        // 节点为叶节点时，保存路径并返回
        if (node->left == nullptr && node->right == nullptr){
            res.push_back(path);
            return ;
        }

        // 节点左/右子树存在时，遍历左/右子树
        if (node->left){
            traversal(node->left, path + "->", res);
        }
        if (node->right){
            traversal(node->right, path +"->", res);
        }
    }
};

class SolutionPreorderTraversal {
public:
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::stack<TreeNode*> treeSt;
        std::stack<std::string> pathSt;     // 每个节点对应的路径
        std::vector<std::string> res;

        if (root == nullptr)    return res;
        treeSt.push(root);
        pathSt.push(std::to_string(root->val));

        while (!treeSt.empty()){
            // 路径栈与 节点栈同步出栈
            TreeNode* node = treeSt.top();      treeSt.pop();
            std::string path = pathSt.top();    pathSt.pop();
            // 叶节点保存路径
            if (node->left == nullptr && node->right == nullptr){
                res.push_back(path);
            }
            // 节点有左/右子树时，保存当前节点至路径中
            if (node->right){
                treeSt.push(node->right);
                pathSt.push(path + "->" + std::to_string(node->right->val));
            }

            if (node->left){
                treeSt.push(node->left);
                pathSt.push(path + "->" + std::to_string(node->left->val));
            }
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

    std::vector<std::string> res = {"0->1->3",
                                    "0->1->4",
                                    "0->2->5",
                                    "0->2->6"};
    Solution sol;
    assert(sol.binaryTreePaths(&a) == res);

    SolutionPreorderTraversal solPreorderTraversal;
    assert(solPreorderTraversal.binaryTreePaths(&a) == res);

    return 0;
}
