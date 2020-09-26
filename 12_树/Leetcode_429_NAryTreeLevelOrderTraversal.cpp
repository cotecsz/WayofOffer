//
// Created by Yang Shuangzhen on 2020/9/26.
//

#include <vector>
#include <queue>

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
    std::vector<std::vector<int>> levelorder(Node* root){
        std::vector<std::vector<int>> res;
        std::queue<Node*> que;
        if (root != nullptr)    que.push(root);

        while(!que.empty()){
            int size = que.size();
            std::vector<int> vec;

            for (int i=0; i<size; i++){
                Node* node = que.front();
                que.pop();

                vec.push_back(node->val);
                for (auto child : node->children){
                    que.push(child);
                }
            }
            res.push_back(vec);
        }

        return res;
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
    std::vector<std::vector<int>> res = {{0},
                                         {2, 1, 3},
                                         {4, 5}};
    assert(sol.levelorder(&a) == res);

    return 0;
}

