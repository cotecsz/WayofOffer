//
// Created by Yang Shuangzhen on 2020/7/20.
//

#include <set>
#include <iostream>
using namespace std;


/*
 *  Leetcode 142 环形链表
 *          基本思路：
 *              方法1：使用set，遍历链表，依次将节点插入set，同时查找set中是否存在节点
 *              方法2：快慢指针
 *                    1. 快指针走两步，慢指针走一步，相交时找出meet节点
 *                    2. 判断meet 节点是否为空，若为空则返回null
 *                    3. meet 节点 和 head 节点同时走，相遇则为 相交节点（2*(a+b) = a + b + c + b
 *
 */

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){}
};

//class Solution {
//public:
//    ListNode *detectCycle(ListNode *head) {
//        set<ListNode*> nodeSet;
//        while(head){
//            if (nodeSet.find(head) != nodeSet.end())
//                return head;
//            nodeSet.insert(head);
//            head = head->next;
//        }
//        return nullptr;
//    }
//};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* meet = nullptr;

        while(fast){
            slow = slow->next;
            fast = fast->next;

            if(!fast){
                return nullptr;
            }
            fast = fast->next;
            if (fast == slow){
                meet = fast;
                break;
            }
        }

        if (meet == nullptr){
            return nullptr;
        }

        while(head && meet){
            if(head == meet)
                return head;
            head = head->next;
            meet = meet->next;
        }
        return nullptr;
    }
};


int main(){
    ListNode a(5);
    ListNode b(6);
    ListNode c(1);
    ListNode d(8);
    ListNode e(4);
    ListNode f(7);
    ListNode g(4);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    g.next = &d;

    ListNode* head = &a;

    Solution sol;
    ListNode* interNode = sol.detectCycle(head);

    cout << interNode->val << endl;

    return 0;
}