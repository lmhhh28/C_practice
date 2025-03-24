#include<iostream>
#include<cstring>
using namespace std;

class Laboratory {
    private:
        int room_no, capacity;
        char* name;
    public:
        Laboratory() {
            name = new char[40];
            Set(0, 0, "NULL");
        }
        Laboratory(int room_noes, int capacities, char* names) {
            name = new char[40];
            Set(room_noes, capacities, names);
        }
        void Set(int room_noes, int capacities, char* names) {
            room_no = room_noes;
            capacity = capacities;
            strcpy(name, names);
        }
        void Set() {
            Set(99999, 1000, "None");
        }
        int GetRoom_no() {
            return room_no;
        }
        int GetCapacity() {
            return capacity;
        }
        char* GetName() {
            return name;
        }
        void Show() {
            cout<<GetRoom_no()<<"/"<<GetCapacity()<<"/"<<GetName()<<endl;
        }
};

int main()
{
    Laboratory L1;
    cout<<"Show object L1:";
    cout<<L1.GetRoom_no()<<"/"<<L1.GetCapacity()<<"/"<<L1.GetName()<<endl;
    int room_no;
    int capacity;
    char name[20];
    cin>>room_no>>capacity>>name;
    Laboratory L2(room_no,capacity,name);
    cout<<"Show object L2:";
    cout<<L2.GetRoom_no()<<"/"<<L2.GetCapacity()<<"/"<<L2.GetName()<<endl;
    cin>>room_no>>capacity>>name;
    cout<<"Reset and Show object L1:";
    L1.Set(room_no,capacity,name);
    L1.Show();
    cout<<"Reset and Show object L2:";
    L2.Set();
    L2.Show();
    return 0;
}