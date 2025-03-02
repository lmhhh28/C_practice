#include <iostream>
using namespace std;
int foo() {
    return 0;
}

namespace A {
    int foo() { return 1; }
    namespace B {
        int foo() { return 2; }
    }
}

int main() {
    cout << foo() << endl;
    cout << A::foo() << endl;
    cout << A::B::foo() << endl;
    {
        using namespace A;
        cout << ::foo() << endl;
        cout << A::foo() << endl;
        cout << B::foo() << endl;
        cout << A::B::foo() << endl; 
    }

    {
        using namespace A::B;
        cout << ::foo() << endl;
        cout << A::foo() << endl;
        cout << A::B::foo() << endl;
        // cout << B::foo() << endl;
    }
}