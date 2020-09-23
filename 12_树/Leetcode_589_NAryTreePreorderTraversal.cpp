//
// Created by Yang Shuangzhen on 2020/9/23.
//

#include <utility>
#include <vector>

class Node{
public:
    int val;
    std::vector<Node*> children;

    Node(){}
    Node(int _val): val(_val){}
    Node(int _val, std::vector<Node*> _children): val(_val), children(std::move(_children)){}
};

class Solution{
public:
    std::vector<int> preorder(Node* root){
        std::vector<int> res;
        traversal(root, res);
        return res;
    }

    void traversal(Node* root, std::vector<int>& res){
        if (root == nullptr)    return;

        res.push_back(root->val);
        for (auto child : root->children){
            traversal(child, res);
        }
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
    std::vector<int> res = {0, 2, 4, 5, 1, 3};
    assert(sol.preorder(&a) == res);

    return 0;
}
