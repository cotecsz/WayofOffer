//
// Created by Yang Shuangzhen on 2020/7/20.
//

#include <iostream>
#include <set>
using namespace std;


/*
 * Leetcode 160 相交链表
 *      基本思路：
 *            方法1：使用集合找出链表起始不同的位置
 *                  时间复杂度：O(nlogn)
 *                  空间复杂度：O(n)
 *            方法2：
 *                  1. 求出两个链表的长度
 *                  2. 将较长链表向前走 longlen - shortlen
 *                  3. 然后同时向后移动，知道两个链表头相等
 *            方法3： a + b + c = b + c + a
 *
 */

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){}
};


//class Solution {
//public:
//    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//        set<ListNode*> nodeSet;
//        while (headA){
//            nodeSet.insert(headA);
//            headA = headA->next;
//        }
//
//        while (headB){
//            if (nodeSet.find(headB) != nodeSet.end())
//                return headB;
//            headB = headB->next;
//        }
//
//        return nullptr;
//    }
//};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int ListALen = get_list_length(headA);
        int ListBLen = get_list_length(headB);

        if (ListALen > ListBLen)
            headA = forward_long_list(ListALen, ListBLen, headA);
        else
            headB = forward_long_list(ListALen, ListBLen, headB);

        while (headA && headB){
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return nullptr;
    }

    int get_list_length(ListNode* head){
        int len = 0;
        while (head){
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode* forward_long_list(int longLen, int shortLen, ListNode* head){
        int delta = longLen - shortLen;
        while (head && delta){
            head = head->next;
            delta--;
        }
        return head;
    }
};

int main(){
    ListNode a(5);
    ListNode b(6);
    ListNode c(1);
    ListNode d(8);
    ListNode e(4);
    ListNode f(5);



    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = nullptr;

    ListNode g(4);
    ListNode h(1);

    g.next = &h;
    h.next = &d;

    ListNode* headA = &a;
    ListNode* headB = &g;

    Solution sol;
    ListNode* node = sol.getIntersectionNode(headA, headB);
    cout << node->val << endl;

    return 0;
}
