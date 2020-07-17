//
// Created by Yang Shuangzhen on 2020/7/17.
//

#include <iostream>
#include <stack>
using namespace std;

/*
 *  leetcode 155 实现一个最小栈
 *
 *      1. push(x)
 *      2. pop()
 *      3. top()
 *      4. getMin()
 *
 *    实现思路：
 *      使用一个栈保存每个元素对应的最小值，则每次压入新数据时，直接判断最小栈的栈顶与新元素的大小，更新最小栈
 *
 */

class MinStack{
public:
    MinStack(){

    }

    void push(int x) {
        _data.push(x);
        if (_min.empty())
            _min.push(x);
        else if (_min.top() < x)
            _min.push(_min.top());
        else
            _min.push(x);
    }

    void pop(){
        _data.pop();
        _min.pop();
    }

    int top(){
        return _data.top();
    }

    int getMin(){
        return _min.top();
    }

private:
    stack<int> _data;
    stack<int> _min;
};

int main(){
    MinStack minS;
    minS.push(1);
    minS.push(3);
    minS.push(-5);

    assert(minS.getMin() == -5);

    minS.pop();
    assert(minS.getMin() == 1);

    assert(minS.top() == 3);

}