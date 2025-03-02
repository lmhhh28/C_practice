#include <iostream>
#include <exception>
#include <string>

class Test {
    private:
        int id;
    public:
        Test(int ids) : id(ids) {
            std::cout << "creating: " << id << std::endl;
        }
        ~Test() {
            std::cout << "releasing: " << id << std::endl;
        }
};

class my_exception : public std::exception {
	private:
		std::string message;
	public:
		my_exception(const std::string& msg) : message(msg) {}
		~my_exception() {}
		const char* what() const noexcept override {
            return message.c_str();
        }
};

void fun_3() {
    Test test_3(3);
    throw std::runtime_error("runtime_error in fun_3!");
}

void fun_2() {
    Test test_2(2);
    try {
        fun_3();
    }
    catch(const std::runtime_error& error) {
        std::cout << error.what() << std::endl;
    }
}

void fun_1() {
    Test test_1(1);
    fun_2();
}

int main() {
    fun_1();
}