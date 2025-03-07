#include <iostream>
// using std::cout;
// using std::endl;
// using std::cin;
using namespace std;

int main() {
	try {
		int num;
		cin >> num;
		if(num == 1) {
			throw 42;	// 抛出整数异常
		} else if(num == 2) {
			throw "String Exception!";	// 抛出字符串异常
		} else {
			throw runtime_error("Unknown Exception!");	// 抛出标准异常
		}
	}
	catch(const int error) {
		cout << "caught int exception: " << error << endl;
	}
	catch(const char* error) {
		cout << "caught string exception: " << error << endl;
	}
	catch(const exception& error) {
		cout << "caught standard exception: " << error.what() << endl;
	}
	return 0;
}
