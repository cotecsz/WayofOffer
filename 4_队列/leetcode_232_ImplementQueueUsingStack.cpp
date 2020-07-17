//
// Created by Yang Shuangzhen on 2020/7/17.
//

#include <iostream>
#include <stack>
using namespace std;


/*
 * leetcode 232 栈实现队列
 *     1. push(x)
 *     2. pop()
 *     3. peek()
 *     4. empty()
 *
 *     实现思路：利用栈的 FILO 特性
 *         1. 将原有数据放入 临时栈
 *         2. 将新数据放入临时栈
 *         3. 将临时栈中的数据 放入 _data
 *
 *     时间复杂度：O(n)
 */
class MyQueue{
public:
    void push(int x){
        stack<int> tmpStack;

        // 调换次序： 将 原来数据放入临时栈中，再将 新元素放入 临时栈中，将临时栈中数据放入 _data 中
        while (!_data.empty()) {
            tmpStack.push(_data.top());
            _data.pop();
        }
        tmpStack.push(x);

        while (!tmpStack.empty()){
            _data.push(tmpStack.top());
            tmpStack.pop();
        }
    }

    int pop(){
        int elem = _data.top();
        _data.pop();
        return elem;
    }

    int peek(){
        return _data.top();
    }

    bool empty(){
        return _data.empty();
    }

private:
    stack<int> _data;
};

int main(){
    MyQueue Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);

    cout << "Q peek is " << Q.peek() << endl;

    Q.pop();
    cout << "Q pop" << endl;

    cout << "Q peek is " << Q.peek() << endl;

    return 0;
}

