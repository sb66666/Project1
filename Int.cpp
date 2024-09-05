#include "Int.h"

using namespace std;

    // 构造函数
    Int(T value) : val(value) {}

    // 只读成员函数
    T value() const
    {
        return val;
    }

    // 获取统计数据
    static int get_compare_count()
    {
        return compare_count;
    }
    static int get_swap_count()
    {
        return swap_count;
    }

    // 友元函数声明
    template<typename U>
    friend bool operator<(const Int<U>& a, const Int<U>& b);

    template<typename U>
    friend void swap(Int<U>& a, Int<U>& b);
};

// 静态成员变量初始化
template <typename T>
int Int<T>::compare_count = 0;

template <typename T>
int Int<T>::swap_count = 0;

// 友元函数实现小于运算符
template <typename T>
bool operator<(const Int<T>& a, const Int<T>& b)
{
    ++Int<T>::compare_count;
    return a.val < b.val;
}

// 友元函数实现交换操作
template <typename T>
void swap(Int<T>& a, Int<T>& b)
{
    ++Int<T>::swap_count;
    T temp = a.val;
    a.val = b.val;
    b.val = temp;
}
