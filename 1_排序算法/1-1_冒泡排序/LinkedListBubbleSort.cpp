//
// Created by Yang Shuangzhen on 2020/10/13.
//

#include <algorithm>
#include <iostream>

struct Node{
    int val;
    Node* next;
    Node(int val, Node* next) : val(val), next(next){}
};

Node* swap(Node* lnd, Node* rnd){
    Node* tmp = rnd->next;
    rnd->next = lnd;
    lnd->next = tmp;
    return rnd;
}

Node* LinkedListBubbleSort(Node* head){
    if (head == nullptr)    return nullptr;

    bool sorted = false;
    Node* cur = head;
    while (!sorted && cur->next != nullptr){
        sorted = true;
        Node* nCur = cur->next;
        while (cur->next != nullptr){
            if (cur->val > cur->next->val){
                std::swap(cur->val, cur->next->val);
                sorted = false;
            }
            cur = cur->next;
        }
        cur = nCur;
    }

    return head;
}

// Todo: 指针反转
Node* LinkedListBubbleSortPointer(Node* head){
    if (head == nullptr)    return nullptr;

    bool sorted = false;
    Node* cur = head;

    Node* nCur = head->next;
    while (!sorted && nCur->next != nullptr){
        sorted = true;
        Node* h = cur->next;
        while (nCur != nullptr){
            if (cur->val > nCur->val){
                // std::swap(cur->val, cur->next->val);
                cur = swap(cur, nCur);
                sorted = false;
            }
            cur = cur->next;
            nCur = cur->next;
        }
        h = h->next;
    }

    return head;
}

int main(){
    Node node_3(3, nullptr);
    Node node_5(5, &node_3);
    Node node_2(2, &node_5);
    Node node_4(4, &node_2);
    Node node_1(1, &node_4);

    Node* head = LinkedListBubbleSort(&node_1);
    Node* cur = head;
    while (cur){
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
    return 0;
}
