#include<iostream>
#include<cstring>
using namespace std;

class Student{
    private:
        int id,score;
        char name[9];
    public:
        Student(int d_id,char *s_name,int d_score){
            id = d_id;
            strcpy(name,s_name);
            score = d_score;
        }
        Student():id(10000),name("NULL"),score(0){}
        ~Student(){}
        int GetId(){return id;}
        char* GetName(){return name;}
        int GetScore(){return score;}
        void Set(int no,char *xm,int s);
        void Set();
        void Show();
};

void Student::Set(int d_id,char *s_name,int d_score){
        id = d_id;
        strcpy(name,s_name);
        score = d_score;
}

void Student::Set(){
        id = 99999;
        strcpy(name,"NONAME");
        score = 100;
}

void Student::Show(){
    cout<<GetId()<<"-"<<GetName()<<"-"<<GetScore()<<endl;
}


int main()
{
    Student stu1;
    cout<<"Show object stu1:";
    cout<<stu1.GetId()<<"-"<<stu1.GetName()<<"-"<<stu1.GetScore()<<endl;
    int no,s;
    char xm[9];
    cin>>no>>xm>>s;
    Student stu2(no,xm,s);
    cout<<"Show object stu2:";
    cout<<stu2.GetId()<<"-"<<stu2.GetName()<<"-"<<stu2.GetScore()<<endl;
    cin>>no>>xm>>s;
    cout<<"Reset and Show object stu1:";
    stu1.Set(no,xm,s);
    stu1.Show();
    cout<<"Reset and Show object stu2:";
    stu2.Set();
    stu2.Show();
    return 0;
}