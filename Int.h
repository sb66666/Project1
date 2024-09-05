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
    // ���캯��
    Int(T value) : val(value);

    // ֻ����Ա����
    T value() const;


    // ��ȡͳ������
    static int get_compare_count();

    static int get_swap_count();


    // ��Ԫ��������
    template<typename U>
    friend bool operator<(const Int<U>& a, const Int<U>& b);

    template<typename U>
    friend void swap(Int<U>& a, Int<U>& b);
};

// ��Ԫ����ʵ��С�������
template <typename T>
bool operator<(const Int<T>& a, const Int<T>& b);


// ��Ԫ����ʵ�ֽ�������
template <typename T>
void swap(Int<T>& a, Int<T>& b);

