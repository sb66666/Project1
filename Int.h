#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Int {
private:
    T val;
    static int compare_count;
    static int swap_count;

public:
    // 构造函数
    Int(T value) : val(value);

    // 只读成员函数
    T value() const;


    // 获取统计数据
    static int get_compare_count();

    static int get_swap_count();


    // 友元函数声明
    template<typename U>
    friend bool operator<(const Int<U>& a, const Int<U>& b);

    template<typename U>
    friend void swap(Int<U>& a, Int<U>& b);
};

// 友元函数实现小于运算符
template <typename T>
bool operator<(const Int<T>& a, const Int<T>& b);


// 友元函数实现交换操作
template <typename T>
void swap(Int<T>& a, Int<T>& b);

