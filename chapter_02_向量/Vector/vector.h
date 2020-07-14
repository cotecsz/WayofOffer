//
// Created by Yang Shuangzhen on 2020/7/8.
//

typedef int Rank;
#define DEFAULT_CAPACITY 3

template <typename T>
class Vector{
protected:
    Rank _size;     // 规模（实际大小）
    int _capacity;  // 容量
    T* _elem;       // 数据
    void copyFrom(T const* a, Rank lo, Rank hi);    // 复制数组区间A[lo, hi]


public:
    Vector(int c=DEFAULT_CAPACITY, int s=0, T v=0)  {
        _elem = new T[_capacity = c];
        for (_size=0; _size < s; size++)
            _elem[_size] = v;
    }
    Vector(T const* A, Rank n)  {copyFrom(A, lo, hi);}


};

