//
// Created by Yang Shuangzhen on 2020/9/6.
//

#include <string>

class Solution {
public:
    bool isUnique(std::string astr) {
        int countStr[128] = {0};
        for (int i=0; i<astr.size(); i++){
            countStr[astr[i]]++;
            if (countStr[astr[i]] > 1)  return false;
        }

        return true;
    }
};

int main(){
    std::string str{"Leetcode"};

    Solution sol;
    assert(!sol.isUnique(str));

    return 0;
}
