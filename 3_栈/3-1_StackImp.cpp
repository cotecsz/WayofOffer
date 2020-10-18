//
// Created by Yang Shuangzhen on 2020/7/17.
//

#include <iostream>
#include <string>
using namespace std;

/*
 * n 次操作 ( 1 <= n <= 10^5)
 * 实现一个栈：
 *    1. 入栈
 *    2. 出栈
 *    3. 询问栈中某个位置元素
 *
 */
const int N = 100005;


string Stack[N];
const int n = 0;
int top = 0;


void push(string name){
    Stack[++top] = name;
}

string pop(){
    return Stack[top--];
}

string query(int pos){
    return Stack[pos];
}


int main(){
    int n;
    cin >> n;
    char name[20];

    for (; n--;){
        int op;
        cin >> op;
        if (op == 1){
            cin >> name;
            push(name);
        }
        else if (op == 2){
            cout << pop() << endl;
        }
        else{
            int pos;
            cin >> pos;
            cout << query(pos) << endl;
        }
    }
    return 0;
}

