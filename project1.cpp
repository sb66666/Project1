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

// �Ƚ�����Int����ĺ���
template <typename T>
void compare(const Int<T>& a, const Int<T>& b)
{
    if (a < b)
    {
        cout << a.value() << " С�� " << b.value() << endl;
    }
    else
    {
        cout << a.value() << " ��С�� " << b.value() << endl;
    }
}

int main() {
    Int<int> a(5);   // ʹ�� int ����
    Int<int> b(10);

    cout << "����ǰ: a = " << a.value() << ", b = " << b.value() << endl;
    compare(a, b);
    swap(a, b);
    cout << "������: a = " << a.value() << ", b = " << b.value() << endl;
    cout << "�Ƚϴ���(int): " << Int<int>::get_compare_count() << endl;
    cout << "��������(int): " << Int<int>::get_swap_count() << endl;

    Int<long> c(100);  // ʹ�� long ����
    Int<long> d(50);

    cout << "����ǰ: c = " << c.value() << ", d = " << d.value() << endl;
    compare(c, d);
    swap(c, d);
    cout << "������: c = " << c.value() << ", d = " << d.value() << endl;
    cout << "�Ƚϴ��� (long): " << Int<long>::get_compare_count() << endl;
    cout << "�������� (long): " << Int<long>::get_swap_count() << endl;

    return 0;
}
