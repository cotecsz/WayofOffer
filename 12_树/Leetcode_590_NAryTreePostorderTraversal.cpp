//
// Created by Yang Shuangzhen on 2020/9/23.
//
#include <vector>

class Node{
public:
    int val;
    std::vector<Node*> children;
    Node(int _val): val(_val){}
    Node(int _val, std::vector<Node*> _children): val(_val), children(_children) {}
};

class Solution{
public:
    std::vector<int> postorder(Node* root){
        std::vector<int> res;
        traversal(root, res);
        return res;
    }

    void traversal(Node* root, std::vector<int> &res){
        if (root == nullptr)    return;
        
        for (auto child : root->children){
            traversal(child, res);
        }
        res.push_back(root->val);
    }
};

int main(){
/*
     *                  a 0
     *              /     |    \
     *          c 2      b 1     d 3
     *       /     \
     *   f 4         g 5
     *
     */
    Node f(5);
    Node e(4);
    std::vector<Node*> childrenOfc({&e, &f});
    Node c(2, childrenOfc);

    Node b(1);
    Node d(3);
    std::vector<Node*> childrenOfa({&c, &b, &d});
    Node a(0, childrenOfa);

    Solution sol;
    std::vector<int> res = {4, 5, 2, 1, 3, 0};
    assert(sol.postorder(&a) == res);
    return 0;
}
