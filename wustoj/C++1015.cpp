#include<iostream>
#include<cstring>
using namespace std;

class Person {
    private:
        char* name;
        char* sex;
        int age;
        void init() {
            name = new char[20];
            sex = new char[10];
        }
    public:
        Person() {
            init();
            Set("NULL", "NO", 0);
        }
        Person(char* names, char* sexes, int ages) {
            init();
            Set(names, sexes, ages);
        }
        void Set(char* names, char* sexes, int ages) {
            strcpy(name, names);
            strcpy(sex, sexes);
            age = ages;
        }
        void Set() {
            Set("Unknown", "FM", 1000);
        }
        char* GetName() {
            return name;
        }
        char* GetSex() {
            return sex;
        }
        int GetAge() {
            return age;
        }
        void Show() {
            cout<<GetName()<<","<<GetSex()<<","<<GetAge()<<endl;
        }

};

int main()
{
    Person p1;
    cout<<"Show object p1:";
    cout<<p1.GetName()<<","<<p1.GetSex()<<","<<p1.GetAge()<<endl;
    char name[20],sex[10];
    int age;
    cin>>name>>sex>>age;
    Person p2(name,sex,age);
    cout<<"Show object p2:";
    cout<<p2.GetName()<<","<<p2.GetSex()<<","<<p2.GetAge()<<endl;
    cin>>name>>sex>>age;
    cout<<"Reset and Show object p1:";
    p1.Set(name,sex,age);
    p1.Show();
    cout<<"Reset and Show object p2:";
    p2.Set();
    p2.Show();
    return 0;
}