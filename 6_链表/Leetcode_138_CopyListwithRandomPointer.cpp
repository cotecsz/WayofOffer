//
// Created by Yang Shuangzhen on 2020/7/21.
//


#include <iostream>
#include <map>
#include <vector>
using namespace std;

/*
 * Leetcode 138 复制带随机指针的链表
 *      基本思路：关键点是对于随机指针的复制，这里使用map进行指针的映射。
 *              1. 首先建立 原始链表节点与随机指针指向的节点位置的映射，同时复制链表
 *              2. 遍历新的链表，通过映射将位置映射回链表
 *
 *              节点 --> 位置    位置-->节点
 */

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, int> nodeMap;
        vector<Node*> nodeVec;
        Node* ptr = head;

        int i = 0;
        while(ptr){
            nodeVec.push_back(new Node(ptr->val));
            nodeMap[ptr] = i;
            ptr = ptr->next;
            i++;
        }

        nodeVec.push_back(nullptr);
        ptr = head; i = 0;
        while(ptr){
            nodeVec[i]->next = nodeVec[i+1];
            if (ptr->random)
                nodeVec[i]->random = nodeVec[nodeMap[ptr->random]];
            ptr = ptr->next;
            i++;
        }

        return nodeVec[0];
    }
};

int main(){
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);
    Node e(50);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    a.random = &c;
    b.random = &d;
    c.random = &c;
    e.random = &d;

    Node* head = &a;

    Solution sol;
    Node* RandomListHead = sol.copyRandomList(head);
    while(RandomListHead){
        cout << RandomListHead->val << " ";
        if (RandomListHead->random)
            cout << RandomListHead->random->val << endl;
        else
            cout << endl;
        RandomListHead = RandomListHead->next;
    }
}

