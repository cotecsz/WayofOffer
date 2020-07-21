//
// Created by Yang Shuangzhen on 2020/7/20.
//

#include <iostream>
using namespace std;

struct ListNode{
    int val{};
    ListNode* next;
    ListNode():next(nullptr){}
    explicit ListNode(int x): val(x), next(nullptr){}
};

int main(){
    ListNode a; a.val = 10;
    ListNode b; b.val = 20;
    ListNode c; c.val = 30;
    ListNode d; d.val = 40;
    ListNode e; e.val = 50;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = nullptr;

    ListNode* head = &a;
    while (head){
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}

