//
// Created by Yang Shuangzhen on 2020/7/17.
//

#include <iostream>
#include <stack>
using namespace std;

/*
 * STl stack 基本操作
 *     1. S.top() 取出栈顶
 *     2. S.empty() 判断栈是否为空
 *     3. S.push(x) 将x 添加至栈
 *     4. S.pop()   弹出栈顶
 *     5. S.size()  栈的存储个数
 *
 */

int main(){
    std::stack<int> myStack;

    if (myStack.empty()){
        cout << "Stack is empty!!!" << endl;
    }

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    cout << "Stack top is " << myStack.top() << endl;
    myStack.pop();
    cout << "Stack pop " << endl;

    cout << "Stack top is " << myStack.top() << endl;
    cout << "Stack size is " << myStack.size() << endl;

    return 0;
}

