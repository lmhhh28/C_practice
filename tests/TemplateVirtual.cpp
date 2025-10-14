#include <iostream>

template <class T>
class baseClass {
public:
    static constexpr T val = 42;
    virtual void showCase() = 0;
    virtual ~baseClass() {}
};

template <class T>
class subClass_1 : public baseClass<T> {
protected:
    void showCase() override {
        std::cout << "This is subClass_1 " << typeid(T).name() << " :" << this->val << std::endl;
    }
    ~subClass_1() {}
};

template <class T>
class subClass_2 : public baseClass<T> {
protected:
    void showCase() override {
        std::cout << "This is subClass_2 " << typeid(T).name() << " :" << this->val << std::endl;
    }
    ~subClass_2() {}
};

template <class T>
class subClass_3 : public baseClass<T> {
protected:
    void showCase() override {
        std::cout << "This is subClass_3 " << typeid(T).name() << " :" << this->val << std::endl;
    }
    ~subClass_3() {}
};

template <class T>
void print(baseClass<T>* ptr) {
    ptr->showCase();
}

int main() {
    baseClass<int>* ptr_1 = new subClass_1<int>();
    baseClass<double>* ptr_2 = new subClass_2<double>();
    baseClass<int>* ptr_3 = new subClass_3<int>();

    print(ptr_1);
    print(ptr_2);
    print(ptr_3);

    delete ptr_1;
}
