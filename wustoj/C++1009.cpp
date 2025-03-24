#include<iostream>
#include<cstring>
using namespace std;

class Country {
    private:
        char* name;
        char* capital;
        int population;
        void init() {
            name = new char[40];
            capital = new char[40];
        }
    public:
        Country(char* names, char* capitals, int populations) {
            init();
            Set(names, capitals, populations);
        }
        Country() {
            init();
            Set("NULL", "NONE", 0);
        }
        char* GetName();
        char* GetCapital();
        int GetPopulation();
        void Set(char* names, char* capitals, int population);
        void Set();
        void Show();
};

char* Country::GetName() {
    return name;
}

char* Country::GetCapital() {
    return capital;
}

int Country::GetPopulation() {
    return population;
} 

void Country::Set(char* names, char* capitals, int populations) {
    strcpy(name, names);
    strcpy(capital, capitals);
    population = populations;
}

void Country::Set() {
    Set("China", "Beijing", 1400000000);
}

void Country::Show() {
    cout << name << '-' << capital << '-' << population << endl;
}

int main()
{
    Country c1;
    cout<<"Show object c1:";
    cout<<c1.GetName()<<"-"<<c1.GetCapital()<<"-"<<c1.GetPopulation()<<endl;
    char name[40],capital[40];
    int population;
    cin>>name>>capital>>population;
    Country c2(name,capital,population);
    cout<<"Show object c2:";
    cout<<c2.GetName()<<"-"<<c2.GetCapital()<<"-"<<c2.GetPopulation()<<endl;
    cin>>name>>capital>>population;
    cout<<"Reset and Show object c1:";
    c1.Set(name,capital,population);
    c1.Show();
    cout<<"Reset and Show object c2:";
    c2.Set();
    c2.Show();
    return 0;
}