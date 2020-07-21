//
// Created by Yang Shuangzhen on 2020/7/20.
//


#include <iostream>
using namespace std;

/*
 * Leetcode 206 反转链表
 *     基本思路：（画出示例）
 *             1. 分为两个原始链表和新链表
 *             2. 新建指针指向 head 的下一个节点（保留原始链表）
 *             3. 反转，更新head 的next（指向新链表），更新新链表头节点（指向head）
 *             4. 更新head
 */
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){}
};

class Solution{
public:
    ListNode* reverseList(ListNode* head){
        ListNode* newHead = nullptr;

        while (head){
            ListNode* next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }

        return newHead;
    }
};


int main(){
    ListNode a(10);
    ListNode b(20);
    ListNode c(30);
    ListNode d(40);
    ListNode e(50);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = nullptr;

    ListNode* head = &a;
//    while (head){
//        cout << head->val << " ";
//        head = head->next;
//    }

    Solution sol;
    ListNode* newHead = nullptr;
    newHead = sol.reverseList(head);
    while (newHead){
        cout << newHead->val << " ";
        newHead = newHead->next;
    }

    return 0;
}
