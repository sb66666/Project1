#include "Int.h"

using namespace std;

    // ���캯��
    Int(T value) : val(value) {}

    // ֻ����Ա����
    T value() const
    {
        return val;
    }

    // ��ȡͳ������
    static int get_compare_count()
    {
        return compare_count;
    }
    static int get_swap_count()
    {
        return swap_count;
    }

    // ��Ԫ��������
    template<typename U>
    friend bool operator<(const Int<U>& a, const Int<U>& b);

    template<typename U>
    friend void swap(Int<U>& a, Int<U>& b);
};

// ��̬��Ա������ʼ��
template <typename T>
int Int<T>::compare_count = 0;

template <typename T>
int Int<T>::swap_count = 0;

// ��Ԫ����ʵ��С�������
template <typename T>
bool operator<(const Int<T>& a, const Int<T>& b)
{
    ++Int<T>::compare_count;
    return a.val < b.val;
}

// ��Ԫ����ʵ�ֽ�������
template <typename T>
void swap(Int<T>& a, Int<T>& b)
{
    ++Int<T>::swap_count;
    T temp = a.val;
    a.val = b.val;
    b.val = temp;
}
