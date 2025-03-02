#include <iostream>
using namespace std;
template <class T>
class Test {
	private:
		T val;
	public:
		Test(T vals) : val(vals) {
			cout << "this is an general val: " << val << endl;
		} 
};
//对int类型的完全特化
template <>
class Test<int> {
	private:
		int val;
	public:
		Test(int vals) : val(vals) {
			cout << "this is an int val: " << val << endl;
		}
};
//对指针类型的偏特化
template <class T>
class Test<T*> {
	private:
		T* val;
	public:
		Test(T* vals) : val(vals) {
			cout << "this is an ptr val: " << val << endl;
		}
};

int main() {
	Test<int> test_1(42);
	Test<double> test_2(43);
	Test<int*> test_3(0);
}