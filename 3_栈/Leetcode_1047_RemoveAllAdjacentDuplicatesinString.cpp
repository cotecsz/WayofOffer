//
// Created by Yang Shuangzhen on 2020/9/18.
//

#include <string>
#include <stack>

class Solution {
public:
    std::string removeDuplicates(std::string S) {
        std::stack<char> st;
        for (auto c : S){
            if (st.empty() || st.top() != c)
                st.push(c);
            else
                st.pop();
        }

        std::string res;
        while (!st.empty()){
            res += st.top();
            st.pop();
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    std::string s("abbaca");
    Solution sol;
    assert(sol.removeDuplicates(s) == "ca");
}

