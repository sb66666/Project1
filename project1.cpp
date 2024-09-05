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

// 比较两个Int对象的函数
template <typename T>
void compare(const Int<T>& a, const Int<T>& b)
{
    if (a < b)
    {
        cout << a.value() << " 小于 " << b.value() << endl;
    }
    else
    {
        cout << a.value() << " 不小于 " << b.value() << endl;
    }
}

int main() {
    Int<int> a(5);   // 使用 int 类型
    Int<int> b(10);

    cout << "交换前: a = " << a.value() << ", b = " << b.value() << endl;
    compare(a, b);
    swap(a, b);
    cout << "交换后: a = " << a.value() << ", b = " << b.value() << endl;
    cout << "比较次数(int): " << Int<int>::get_compare_count() << endl;
    cout << "交换次数(int): " << Int<int>::get_swap_count() << endl;

    Int<long> c(100);  // 使用 long 类型
    Int<long> d(50);

    cout << "交换前: c = " << c.value() << ", d = " << d.value() << endl;
    compare(c, d);
    swap(c, d);
    cout << "交换后: c = " << c.value() << ", d = " << d.value() << endl;
    cout << "比较次数 (long): " << Int<long>::get_compare_count() << endl;
    cout << "交换次数 (long): " << Int<long>::get_swap_count() << endl;

    return 0;
}
