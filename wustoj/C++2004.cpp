#include<iostream>
#include<cstring>
using namespace std;

class Student {
    private:
        int id, score;
        char* name;
    public:
        Student() : id(0), score(0) {
            name = new char[40];
        }
        ~Student() {}
        friend istream& operator>>(istream& in, Student& student);
        friend ostream& operator<<(ostream& os, Student& student);
        friend bool operator>(Student& stu_1, Student& stu_2);
};

istream& operator>>(istream& in, Student& student) {
    in >> student.id >> student.name >> student.score;
    return in; 
}

ostream& operator<<(ostream& os, Student& student) {
    os << "id=" << student.id << ",name=" << student.name << ",score=" << student.score;
    return os;
}

bool operator>(Student& stu_1, Student& stu_2) {
    return stu_1.score > stu_2.score ? true : stu_1.score < stu_2.score ? false : stu_1.id > stu_2.id ? true : false;
}

int main()
{
    int i,j,n;
    Student t;
    cin>>n;
    Student *stu=new Student[n];
    for(i=0;i<n;i++)
        cin>>stu[i];
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if(stu[j]>stu[j+1])
            {  t=stu[j];  stu[j]=stu[j+1];   stu[j+1]=t;    }
    for(i=0;i<n;i++)
        cout<<i+1<<":"<<stu[i]<<endl;
    delete[]stu;
    return 0;
}