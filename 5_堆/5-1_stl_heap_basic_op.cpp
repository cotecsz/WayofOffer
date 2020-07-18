//
// Created by Yang Shuangzhen on 2020/7/18.
//

#include <queue>
#include <iostream>

using namespace std;


/*
 * 优先队列/ 堆的基本操作：
 *     1. push()
 *     2. pop()
 *     3. empty()
 *     4. top()
 *     5. size()
 */

int main(){
//    priority_queue<int> bigHeap;
    priority_queue<int, vector<int>, greater<int>> smallHeap;
    priority_queue<int, vector<int>, less<int>> bigHeap;

    assert(bigHeap.empty());

    vector<int> num = {9, 20, 100, 999, 10000};
    for (int n: num)
        bigHeap.push(n);

    assert(bigHeap.top() == 10000);
    bigHeap.pop();
    assert(bigHeap.top() == 999);
    bigHeap.pop(); bigHeap.pop(); bigHeap.pop();

    assert(bigHeap.size() == 1);

    return 0;
}

