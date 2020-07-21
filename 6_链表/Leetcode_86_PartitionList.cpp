//
// Created by Yang Shuangzhen on 2020/7/20.
//


#include <iostream>
using namespace std;

/*
 * Leetcode 86 分隔链表
 *      基本思路：
 *              1. 使用两个新的链表头：比元素大的greaterHead 比元素小的lessHead
 *              2. 遍历链表，head = head->next
 *              3. 比指定元素大则加入greaterHead 链表，比指定元素小加入 lessHead 链表
 *              4. 最后分别处理 greaterHead链表和less链表的最后一个节点元素
 *              5. 返回lessHead的下一个节点
 *
 */
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode lessHead(0);
        ListNode greaterHead(0);
        ListNode* PlessHead = &lessHead;
        ListNode* PgreaterHead = &greaterHead;

        while(head){
            if (head->val < x){
                PlessHead->next = head;
                PlessHead = PlessHead->next;
            }
            else{
                PgreaterHead->next = head;
                PgreaterHead = PgreaterHead->next;
            }
            head = head->next;
        }
        PlessHead->next = greaterHead.next;
        PgreaterHead->next = nullptr;

        return lessHead.next;
    }
};


int main(){
    ListNode a(5);
    ListNode b(6);
    ListNode c(1);
    ListNode d(8);
    ListNode e(4);
    ListNode f(9);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = nullptr;

    ListNode* head = &a;
    Solution sol;
    ListNode* sortHead = sol.partition(head, 3);

    while (sortHead){
        cout << sortHead->val << " ";
        sortHead = sortHead->next;
    }

    return 0;
}
