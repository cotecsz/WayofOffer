//
// Created by Yang Shuangzhen on 2020/7/18.
//

#include <stack>
#include <vector>
using namespace std;


/*
 * Leetcode 946: 验证栈序列
 *
 *     基本思路：依次让 pushed 入栈，当栈顶元素与poped相等时，出栈
 *
 *     时间复杂度：O(n)
 *     空间复杂度：O(n)
 */
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> S;

        int j = 0;
        for (int n : pushed){
            S.push(n);
            while (!S.empty()  && j < popped.size() && S.top() == popped[j]){
                S.pop();
                j++;
            }
        }
        return S.empty();
    }
};


int main(){
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> poped = {4, 5, 3, 2, 1};

    Solution sol;
    assert(sol.validateStackSequences(pushed, poped));

    poped = {4, 3, 5, 1, 2};
    assert(!sol.validateStackSequences(pushed, poped));

    return 0;
}

