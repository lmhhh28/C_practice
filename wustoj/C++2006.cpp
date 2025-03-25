#include<iostream>
#include<cstring>
using namespace std;

class Person {
    private:
        int age;
        char* name;
    public:
        Person() : age(0) {
            name = new char[40];
            strcpy(name, "NULL");
        }
        Person(Person&& obj) noexcept : age(obj.age), name(obj.name) {
            obj.name = nullptr;
        }
        Person(int ages) : age(ages) {
            name = new char[40];
            strcpy(name, "NULL");
        }
        ~Person() {
            delete[] name;
        }
        int GetAge() {
            return age;
        }
        Person& operator=(Person&& person) {
            if(this != &person) {
                age = person.age;
                strcpy(name, person.name);
            }
            return *this;
        }
        friend istream& operator>>(istream& in, Person& person);
        friend ostream& operator<<(ostream& os, Person& person);
        friend Person operator+(Person& p_1, Person& p_2);
};

istream& operator>>(istream& in, Person& person) {
    return in >> person.name >> person.age; 
}

Person operator+(Person& p_1, Person& p_2) {
    return move(Person(p_1.age + p_2.age));
}

ostream& operator<<(ostream& os, Person& person) {
    return os << "name=" << person.name << ",age=" << person.age;
}

int main()
{
    int n,i;
    cin>>n;
    Person *person=new Person[n+1];
    for(i=1;i<=n;i++)
        cin>>person[i];
    for(i=0;i<=n;i++)
        cout<<person[i]<<endl;
    for(i=1;i<=n;i++)
        person[0]=person[0]+person[i];
    cout<<"average age:"<<person[0].GetAge()/(double)n<<endl;
    delete[] person;
    return 0;
}