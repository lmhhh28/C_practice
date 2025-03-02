#include <iostream>
#include <exception>
#include <string>

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

int main() {
	try {
		throw my_exception("This is custom exception!");
	}
	catch(const std::exception& error) {
		std::cout << "my_exception: " << error.what() << std::endl;
	}
	return 0;
}