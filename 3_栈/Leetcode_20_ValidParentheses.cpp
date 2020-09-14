//
// Created by Yang Shuangzhen on 2020/9/14.
//


#include <stack>
#include <string>

/*
 * Leetcode 20: 有效括号
 *    基本思路：依次遍历字符串，遇到左括号压入stack，遇到右括号弹出
 *            若在遍历过程中，栈空 / 栈顶元素与当前括号不匹配，返回false
 *            遍历所有字符串，若栈空则返回true
 */
class Solution {
public:
    bool isValid(std::string s) {
        std::stack<int> st;

        for (int i=0; i<s.size(); i++){
            if (s[i] == '{')    st.push('}');
            else if (s[i] == '[')   st.push(']');
            else if (s[i] == '(')   st.push(')');
            else if (s.empty() || st.top() != s[i])  return false;
            else    st.pop();
        }

        return st.empty();
    }
};

int main(){
    std::string parenthese("{[()]}()");

    Solution sol;
    assert(sol.isValid(parenthese));
    return 0;
}



