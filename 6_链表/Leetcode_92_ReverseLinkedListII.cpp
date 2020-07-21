//
// Created by Yang Shuangzhen on 2020/7/20.
//


#include <iostream>
using namespace std;

/*
 * Leetcode 92 反转链表
 *     基本思路：主要是 4 个关键节点的处理
 *             1. 寻找 反转链表的第一个节点的前一个节点
 *             2. 利用 反转长度进行反转链表
 *             3. 更新最后一个节点为null，将其更新为 此时反转链表的最后一个节点的后一个即诶单
 *             4. 判断 m 是否为 1，分别处理
 */

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){}
};

class Solution{
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* result = head;
        // 查找 更新节点的前一个节点
        ListNode* preHead = nullptr;
        int reverseLen = n-m+1;

        while (head && --m){
            preHead = head;
            head = head->next;
        }

        // 反转链表
        ListNode* modifiedListTail = head;
        ListNode* newHead = nullptr;
        while(head && reverseLen){
            ListNode* next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
            reverseLen--;
        }
        modifiedListTail->next = head;      // 此时，head 指向反转节点的下一个节点

        // 如果 m = 1，prehead 为空，则直接
        if (preHead){
            preHead->next = newHead;
        }
        else{
            result = newHead;
        }
        return result;
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
    newHead = sol.reverseBetween(head, 2, 5);
    while (newHead){
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
}
