#include<iostream>
using namespace std;

class SmallInt {
    private:
        int num;
        static int transfer(int number) {
            while(number > 127) {
                number -= 256;
            }
            while(number < -128) {
                number += 256;
            }
            return number;
        }
    public:
        SmallInt() : num(0) {}
        SmallInt(int number) : num(transfer(number)) {}
        friend istream& operator>>(istream& in, SmallInt& number);
        friend ostream& operator<<(ostream& os, SmallInt& number);
        friend SmallInt operator+(SmallInt& num_1, SmallInt& num_2);
        friend SmallInt operator-(SmallInt& num_1, SmallInt& num_2);
        friend SmallInt operator*(SmallInt& num_1, SmallInt& num_2);
        friend SmallInt operator/(SmallInt& num_1, SmallInt& num_2);
};

istream& operator>>(istream& in, SmallInt& number) {
    int temp;
    in >> temp;
    number.num = number.transfer(temp);
    return in;
}

ostream& operator<<(ostream& os, SmallInt& number) {
    return os << number.num;
}

SmallInt operator+(SmallInt& num_1, SmallInt& num_2) {
    return SmallInt(num_1.num + num_2.num);
}

SmallInt operator-(SmallInt& num_1, SmallInt& num_2) {
    return SmallInt(num_1.num - num_2.num);
}

SmallInt operator*(SmallInt& num_1, SmallInt& num_2) {
    return SmallInt(num_1.num * num_2.num);
}

SmallInt operator/(SmallInt& num_1, SmallInt& num_2) {
    return SmallInt(num_1.num / num_2.num);
}

int main()
{
    SmallInt s1,s2,s3;
    cin>>s1>>s2;
    s3=s1+s2;
    cout<<s1<<" + "<<s2<<" = "<<s3<<endl;
    s3=s1-s2;
    cout<<s1<<" - "<<s2<<" = "<<s3<<endl;
    s3=s1*s2;
    cout<<s1<<" * "<<s2<<" = "<<s3<<endl;
    s3=s1/s2;
    cout<<s1<<" / "<<s2<<" = "<<s3<<endl;
    return 0;
}