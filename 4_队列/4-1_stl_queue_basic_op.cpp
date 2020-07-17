//
// Created by Yang Shuangzhen on 2020/7/17.
//

#include <iostream>
#include <queue>
using namespace std;

/*
 * STL Queue 基本操作
 *     1. Q.empty()     队列是否为空
 *     2. Q.front()     队列队首
 *     3. Q.back()      队列队尾
 *     4. Q.push(x)     将元素x 添加至队尾
 *     5. Q.pop()       弹出队首
 *     6. Q.size()      队列长度
 *
 */


int main(){
    queue<int> myQueue;

    if (myQueue.empty()){
        cout << "Queue is empty!!!" << endl;
    }

    myQueue.push(5);
    myQueue.push(10);
    myQueue.push(15);
    cout << "myQueue front is " << myQueue.front() << endl;
    cout << "myQueue back is " << myQueue.back() << endl;

    cout << "myQueue pop front" << endl;
    myQueue.pop();

    cout << "myQueue size is " << myQueue.size() << endl;

    return 0;

}

