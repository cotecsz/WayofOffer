//
// Created by Yang Shuangzhen on 2020/7/21.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 * Leetcode 12 合并K个有序链表
 *      方法1：将所有链表的节点存放之vector中，然后使用sort排序，再进行链接
 *            时间复杂度：
 *      方法2：归并排序
 *            将lists 分开，最后两两合并。
 *
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool cmp(const ListNode* a, const ListNode* b){
    return a->val < b->val;
}

//class Solution {
//public:
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        vector<ListNode*> nodeVec;
//        for (int i=0; i < lists.size(); i++){
//            ListNode* head = lists[i];
//            while (head){
//                nodeVec.push_back(head);
//                head = head->next;
//            }
//        }
//        if (nodeVec.size() == 0)
//            return nullptr;
//        sort(nodeVec.begin(), nodeVec.end(), cmp);
//        for (int i=1; i < nodeVec.size(); i++){
//            nodeVec[i-1]->next = nodeVec[i];
//        }
//        nodeVec[nodeVec.size()-1]->next = nullptr;
//
//        return nodeVec[0];
//    }
//};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        if (lists.size() == 1)
            return lists[0];
        if (lists.size() == 2)
            return mergeTwoLists(lists[0], lists[1]);

        vector<ListNode*> subList1;
        vector<ListNode*> subList2;
        int mid = lists.size() / 2;
        for (int i=0; i< mid; i++)
            subList1.push_back(lists[i]);
        for (int i=mid; i<lists.size();i++)
            subList2.push_back(lists[i]);

        ListNode* l1 = mergeKLists(subList1);
        ListNode* l2 = mergeKLists(subList2);

        return mergeTwoLists(l1, l2);
    }

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
    ListNode h(99);
    ListNode i(100);
    ListNode j(110);

    a.next = &b;
    b.next = &c;
    c.next = nullptr;

    d.next = &e;
    e.next = &f;
    f.next = nullptr;

    h.next = &i;
    i.next = &j;
    j.next = nullptr;

    ListNode* l1 = &a;
    ListNode* l2 = &d;
    ListNode* l3 = &h;
    vector<ListNode*> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);

    Solution sol;

    ListNode* mergeHead = sol.mergeKLists(lists);
    while(mergeHead){
        cout << mergeHead->val << " ";
        mergeHead = mergeHead->next;
    }

    return 0;
}