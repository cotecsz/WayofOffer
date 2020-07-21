//
// Created by Yang Shuangzhen on 2020/7/21.
//


#include <iostream>
using namespace std;

/*
 * Leetcode 21 合并两个有序链表
 *      基本思路：归并排序
 *              1. 新建链表头
 *              2. 依次遍历比较两个链表的链表头，将较小的加入新的链表头
 *              3. 将剩下的链表链接至新链表
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode mergeHead(0);
        ListNode* pre = &mergeHead;

        while (l1 && l2){
            if (l1->val < l2->val){
                pre->next = l1;
                l1 = l1->next;
            }
            else {
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }

        if (l1){
            pre->next = l1;
        }
        if (l2){
            pre->next = l2;
        }

        return mergeHead.next;
    }
};


int main(){
    ListNode a(10);
    ListNode b(20);
    ListNode c(30);
    ListNode d(1);
    ListNode e(4);
    ListNode f(9);

    a.next = &b;
    b.next = &c;
    c.next = nullptr;

    d.next = &e;
    e.next = &f;
    f.next = nullptr;

    ListNode* l1 = &a;
    ListNode* l2 = &d;
    Solution sol;
    ListNode* mergerHead = sol.mergeTwoLists(l1, l2);

    while(mergerHead){
        cout << mergerHead->val << " " ;
        mergerHead = mergerHead->next;
    }

    return 0;
}