//
// Created by Yang Shuangzhen on 2020/7/18.
//

#include <iostream>
#include <queue>

using namespace std;

/*
 *    Leetcode 295: 从数据流中找中位数
 *
 *    基本思路：维护一个最大堆和一个最小堆，维护两个状态：
 *            1. 最大堆的数量与最小堆相同
 *            2. 最大堆的堆顶比最小堆的堆顶小（保证两个堆顶为中位数或其中一个为中位数）
 *
 *            考虑三种情况： 最大堆堆顶 a 最小堆堆顶 b 新元素 c
 *            1. 最大堆与最小堆数量相等
 *               a. 新元素小于最大堆堆顶，直接放入最大堆
 *               b. 新元素大于最大堆堆顶，直接放入最小堆
 *            2. 最大堆比最小堆多一个元素
 *               a. 新元素小于最大堆堆顶，将最大堆堆顶放入最小堆，新元素添加至最大堆
 *               b. 新元素大于最大堆堆顶，直接放入最小堆
 *            3. 最大堆比最小堆少一个元素
 *               a. 新元素小于最小堆堆顶，直接放入最大堆
 *               b. 新元素大于最小堆堆顶，将最小堆堆顶放入最大堆，新元素添加至最小堆
 *
 *            中位数：
 *            1. 最大堆与最小堆个数相同，(最大堆堆顶 + 最小堆堆顶) / 2
 *            2. 最大堆个数比最小堆个数多1，则为 最大堆堆顶
 *            3. 最小堆个数比最大堆个数多1， 则为 最小堆堆顶
 */
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() = default;

    void addNum(int num) {
        if (bigHeap.empty())
            bigHeap.push(num);
        else if(bigHeap.size() == smallHeap.size()){
            if (num < bigHeap.top())
                bigHeap.push(num);
            else
                smallHeap.push(num);
        }
        else if(bigHeap.size() > smallHeap.size()){
            if (num > bigHeap.top()){
                smallHeap.push(num);
            }
            else{
                smallHeap.push(bigHeap.top());
                bigHeap.pop();
                bigHeap.push(num);
            }
        }
        else if (bigHeap.size() < smallHeap.size()){
            if (num < smallHeap.top()){
                bigHeap.push(num);
            }
            else{
                bigHeap.push(smallHeap.top());
                smallHeap.pop();
                smallHeap.push(num);
            }
        }
    }

    double findMedian() {
        if (bigHeap.size() == smallHeap.size())
            return (bigHeap.top() + smallHeap.top()) / 2.0;
        else if (bigHeap.size() > smallHeap.size())
            return bigHeap.top();
        else
            return smallHeap.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> smallHeap;
    priority_queue<int, vector<int>, less<int>> bigHeap;
};

int main(){
    vector<int> nums = {2, 4, 9, 10, 20, 6, 100};
    MedianFinder mf;

    for (int n : nums){
        mf.addNum(n);
    }

    assert(mf.findMedian() == 9);
    return 0;
}