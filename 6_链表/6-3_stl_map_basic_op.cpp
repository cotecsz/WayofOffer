//
// Created by Yang Shuangzhen on 2020/7/21.
//

#include <iostream>
#include <map>
using namespace std;

struct RandomNode{
    int label;
    RandomNode* next, *random;
    RandomNode(int x): label(x), next(nullptr), random(nullptr){}
};

int main(){
    map<RandomNode*, int> nodeMap;
    RandomNode a(10);
    RandomNode b(20);
    RandomNode c(30);
    
    a.next = &b;
    b.next = &c;
    a.random = &c;
    b.random = &a;
    c.random = &c;
    
    nodeMap[&a] = 1;
    nodeMap[&b] = 2;
    nodeMap[&c] = 3;
    
    cout << "a.random id = " << nodeMap[a.random] << endl;
    cout << "b.random id = " << nodeMap[b.random] << endl;
    cout << "c.random id = " << nodeMap[c.random] << endl;

    return 0;
}