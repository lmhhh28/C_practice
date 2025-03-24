#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class Building {
    private:
        char* name;
        double height;
        int floor;
    public:
        Building() {
            name = new char[40];
            Set("NULL", 0, 0);
        }
        Building(char* names, double heights, int floors) {
            name = new char[40];
            Set(names, heights, floors);
        }
        void Set(char* names, double heights, int floors) {
            strcpy(name, names);
            height = heights;
            floor = floors;
        }
        void Set() {
            Set("None", 20, 7);
        }
        char* GetName() {
            return name;
        }
        double GetHeight() {
            return height;
        }
        int GetFloors() {
            return floor;
        }
        void Show() {
            cout<<GetName()<<"--"<<GetHeight()<<"米--"<<GetFloors()<<"层"<<endl;
        }
};

int main()
{
    cout<<fixed<<setprecision(2);
    Building b1;
    cout<<"Show object b1:";
    cout<<b1.GetName()<<"--"<<b1.GetHeight()<<"米--"<<b1.GetFloors()<<"层"<<endl;
    char name[40];
    double height;
    int floors;
    cin>>name>>height>>floors;
    Building b2(name,height,floors);
    cout<<"Show object b2:";
    cout<<b2.GetName()<<"--"<<b2.GetHeight()<<"米--"<<b2.GetFloors()<<"层"<<endl;
    cin>>name>>height>>floors;
    cout<<"Reset and Show object b1:";
    b1.Set(name,height,floors);
    b1.Show();
    cout<<"Reset and Show object b2:";
    b2.Set();
    b2.Show();
    return 0;
}