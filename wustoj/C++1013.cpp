#include<iostream>
#include<cstring>
using namespace std;

class Course {
    private:
        int id, credit;
        char* name;
    public:
        Course() {
            name = new char[40];
            Set(0, "NULL", 0);
        }
        Course(int ids, char* names, int credits) {
            name = new char[40];
            Set(ids, names, credits);
        }
        void Set(int ids, char* names, int credits) {
            id = ids;
            strcpy(name, names);
            credit = credits;
        }
        void Set() {
            Set(9999999, "None", 10000);
        }
        int GetId() {
            return id;
        }
        char* GetName() {
            return name;
        }
        int GetCredit() {
            return credit;
        }
        void Show() {
            cout<<GetId()<<"/"<<GetName()<<"/"<<GetCredit()<<endl;
        }
};

int main()
{
    Course c1;
    cout<<"Show object c1:";
    cout<<c1.GetId()<<"/"<<c1.GetName()<<"/"<<c1.GetCredit()<<endl;
    double id;
    char name[40];
    int credit;
    cin>>id>>name>>credit;
    Course c2(id,name,credit);
    cout<<"Show object c2:";
    cout<<c2.GetId()<<"/"<<c2.GetName()<<"/"<<c2.GetCredit()<<endl;
    cin>>id>>name>>credit;
    cout<<"Reset and Show object c1:";
    c1.Set(id,name,credit);
    c1.Show();
    cout<<"Reset and Show object c2:";
    c2.Set();
    c2.Show();
    return 0;
}