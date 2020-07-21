//
// Created by Yang Shuangzhen on 2020/7/20.
//

#include <vector>
#include <set>
#include <iostream>
using namespace std;

int main(){
    set<int> testSet;
    vector<int> a = {5, 1, 4, 8, 10, 1, 3};
    vector<int> b = {2, 7, 6, 3, 1, 6, 0, 1};

    for (int n : a)
        testSet.insert(n);
    for (int n : b)
        if (testSet.find(n) != testSet.end())
            cout << n << " in array A" << endl;

    return 0;
}

