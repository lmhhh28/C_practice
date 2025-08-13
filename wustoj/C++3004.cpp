#include<iostream>
#include<cstring>
using namespace std;

class Country {
    private:
    char *name, *capital;
    int population;
    void Init() {
        name = new char[40];
        capital = new char[40];
    }
    public:
        Country() : population(0) {
            Init();
            strcpy(name, "Noname");
            strcpy(capital, "Unknown");
            cout << "Function #1 is called!" << endl;
        }
        Country(char *s3, char* s4, int p2) : population(p2) {
            Init();
            strcpy(name, s3);
            strcpy(capital, s4);
            cout << "Function #2 is called!" << endl;
        }
        Country(const Country& obj) : population(obj.population) {
            Init();
            strcpy(name, obj.name);
            strcpy(capital, obj.capital);
        }
        void Show() {
            cout << name << '(' << "Capital:" << capital << " population:" << population << ')' << endl;
            cout << "Function #3 is called!" << endl;
        }

};

class Province : public Country {
    private:
    char *name, *capital;
    int population;
    void Init() {
        name = new char[40];
        capital = new char[40];
    }
    public:
    Province() : population(0), Country() {
        Init();
        strcpy(name, "None");
        strcpy(capital, "None");
        cout << "Function #4 is called!" << endl;
    }
    Province(char *s1, char *s2, int p1, char *s3, char *s4, int p2) 
        : population(p1), Country(s3, s4, p2) {
            Init();
            strcpy(name, s1);
            strcpy(capital, s2);
            cout << "Function #5 is called!" << endl;
        }
    Province(char *s1, char *s2, int p1, const Country& obj) : population(p1), Country(obj) {
        Init();
        strcpy(name, s1);
        strcpy(capital, s2);
        cout << "Function #6 is called!" << endl;
    }
    Province(char *s1, char *s2, int p1) : population(p1), Country() {
        Init();
        strcpy(name, s1);
        strcpy(capital, s2);
        cout << "Function #7 is called!" << endl;
    }
    Province(const Country& obj) : population(0), Country(obj) {
        Init();
        strcpy(name, "None");
        strcpy(capital, "None");
        cout << "Function #8 is called!" << endl;
    }
    void Show() {
        cout << name << ":provincial capital(" << capital << "),population("
             << population << "),Country:";
        Country::Show();
        cout << "Function #9 is called!" << endl;
    }
};

int main()
{
    char s1[40],s2[40],s3[40],s4[40];
    int p1,p2;
    cin>>s1>>s2>>p1>>s3>>s4>>p2;

    Country country0;
    cout<<"Country 0:";  country0.Show();
    Country country1(s3,s4,p2);
    cout<<"Country 1:"; country1.Show();

    Province province0;
    cout<<"Province0:";  province0.Show();
    Province province1(s1,s2,p1,s3,s4,p2);
    cout<<"Province1:"; province1.Show();
    Province province2(s1,s2,p1,country1);
    cout<<"Province2:"; province2.Show();
    Province province3(s1,s2,p1);
    cout<<"Province3:"; province3.Show();
    Province province4(country1);
    cout<<"Province4:"; province4.Show();

    return 0;
}