#include <iostream>

template <int N>
class Fac {
	public:
		static constexpr long long val = N * Fac<N - 1>::val;
};

// 利用特化完成类模板递归的终点

template <>
class Fac<0> {
	public:
		static constexpr long long val = 1;
};

int main() {
	std::cout << Fac<10>::val << std::endl;
}