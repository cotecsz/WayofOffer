//
// Created by Yang Shuangzhen on 2020/7/17.
//

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/* leetcode 225: 用队列实现栈
 *
 *    1. push()
 *    2. pop()
 *    3. top()
 *    4. empty()
 *
 *    实现思路：利用队列的 FIFO 特性 调换次序
 *        1. 将新数据放入临时队列
 *        2. 将原有数据放入 临时队列
 *        3. 将临时队列的数据 放入 _data
 *
 *    时间复杂度：O(n)
 *
 */


class MyStack{
public:
    void push(int x){
        queue<int> tmpQueue;

        tmpQueue.push(x);

        // 调换次序： 将新数据放入临时队列，再将原有数据放入临时队列，最后将 临时队列中数据放入 _data 中
        while (!_data.empty()){
            tmpQueue.push(_data.front());
            _data.pop();
        }
        while (!tmpQueue.empty()){
            _data.push(tmpQueue.front());
            tmpQueue.pop();
        }

    }

    int pop(){
        int elem = _data.front();
        _data.pop();
        return elem;
    }

    int top(){
        return _data.front();
    }

    bool empty(){
        return _data.empty();
    }

private:
    queue<int> _data;
};


int main(){
    MyStack S;
    S.push(1);
    cout << "S size is " << S.size() << endl;

    S.push(2);
    cout << "S size is " << S.size() << endl;

    S.push(3);
    cout << "S size is " << S.size() << endl;


    cout << "S top is " << S.top() << endl;

    cout << "S pop" << endl;
    S.pop();
    cout << "S top is " << S.top() << endl;

    S.push(3);
    cout << "S top is " << S.top() << endl;
    cout << "S size is " << S.size() << endl;
    S.pop();
    cout << "S top is " << S.top() << endl;

    return 0;

}