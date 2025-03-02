#include <iostream>
using namespace std;

template <class T>	// 基本类型模板
void print(T val) {
    cout << "general val: " << val << endl;
}

template <>	// 完全特化
void print<int>(int val) {
    cout << "int val: " << val << endl;
}

template <>
void print<double>(double val) {
    cout << "double val: " << val << endl;
}

// 偏特化：专门针对指针类型
template <class T>
void print(T* val) {
    cout << "ptr val: " << *val << endl;
}

// 偏特化：专门针对引用类型
// template <class T>
// void print(T& val) {
//     cout << "ref val: " << val << endl;
// }

int main() {
    int val_1 = 1;
    double val_2 = 2;
    int* val_3 = &val_1;
    double* val_4 = &val_2;
    // int& val_5 = val_1;
    // double& val_6 = val_2;

    print(val_1);  // 调用完全特化：print<int>(int)
    print(val_2);  // 调用完全特化：print<double>(double)
    print(val_3);  // 调用偏特化：print<int*>(int*)
    print(val_4);  // 调用偏特化：print<double*>(double*)
    // print(val_5);  // 调用偏特化：print<int&>(int&)
    // print(val_6);  // 调用偏特化：print<double&>(double&)
}
