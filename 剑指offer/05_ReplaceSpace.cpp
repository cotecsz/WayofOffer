//
// Created by Yang Shuangzhen on 2020/9/8.
//

#include <string>

class Solution {
public:
    std::string replaceSpace(std::string s) {
        int count = 0;
        for (int i=0; i<s.size(); i++){
            if (s[i] == ' '){
                count++;
            }
        }

        int oldSize = s.size();
        s.resize(s.size() + count*2);
        int newSize = s.size();
        for (int i=oldSize-1, j=newSize-1; i >= 0; i--, j--){
            if (s[i] != ' '){
                s[j] = s[i];
            }
            else{
                s[j] = '%';
                s[j-1] = '0';
                s[j-2] = '2';
                j -= 2;
            }
        }

        return  s;
    }
};


int main(){
    std::string s = "we are family";

    Solution sol;
    assert(sol.replaceSpace(s) == "we20%are20%family");

    return 0;
}


