//
// Created by Yang Shuangzhen on 2020/7/20.
//


#include <iostream>
using namespace std;


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
