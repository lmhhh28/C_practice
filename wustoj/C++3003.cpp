#include<iostream>
#include<cstring>
using namespace std;

class CPU {
    private:
        char *brand, *model;
        void Allocate() {
            brand = new char[40];
            model = new char[40];
        }
    public:
        CPU() {
            Allocate();
            strcpy(brand, "Unknown");
            strcpy(model, "Unknown");
            cout << "Function #1 is called!" << endl;
        }
        CPU(char *s3, char *s4) {
            Allocate();
            strcpy(brand, s3);
            strcpy(model, s4);
            cout << "Function #2 is called!" << endl;
        }
        CPU(const CPU& obj) {
            Allocate();
            strcpy(brand, obj.brand);
            strcpy(model, obj.model);
        }
        void Show() {
            cout << brand << ' ' << model << endl;
            cout << "Function #3 is called!" << endl;
        }
};

class Computer : public CPU {
    private:
        char *factory, *computer;
        int memory, price;
        void Allocate() {
            factory = new char[40];
            computer = new char[40];
        }
    public:
        Computer() : memory(0), price(0), CPU() {
            Allocate();
            strcpy(factory, "None");
            strcpy(computer, "None");
            cout << "Function #4 is called!" << endl;
        }
        Computer(char *s1, char *s2, int ram, int price, char *s3, char *s4)
            : memory(ram), price(price), CPU(s3, s4) {
            Allocate();
            strcpy(factory, s1);
            strcpy(computer, s2);
            cout << "Function #5 is called!" << endl;
        }
        Computer(char *s1, char *s2, int ram, int price) : memory(ram), price(price) {
            Allocate();
            strcpy(factory, s1);
            strcpy(computer, s2);
            cout << "Function #7 is called!" << endl;
        }
        Computer(char *s1, char *s2, int ram, int price, const CPU& cpu)
            : memory(ram), price(price), CPU(cpu) {
            Allocate();
            strcpy(factory, s1);
            strcpy(computer, s2);
            cout << "Function #6 is called!" << endl;
        }
        Computer(const CPU& cpu) : memory(0), price(0), CPU(cpu) {
            Allocate();
            strcpy(factory, "None");
            strcpy(computer, "None"); 
            cout << "Function #8 is called!" << endl;
        }
        void Show() {
            cout << "Brand:" << factory << ' ' << "Type:" << computer 
                 << ' ' << "Memory:" << memory << ' ' << "Price:"
                 << price << ' ' << "CPU:";
            CPU::Show();
            cout << "Function #9 is called!" << endl;
        }
};
 
int main()
{
    char s1[40],s2[40],s3[40],s4[40];
    int ram,price;
    cin>>s1>>s2>>ram>>price>>s3>>s4;

    CPU cpu0;
    cout<<"CPU 0:"; cpu0.Show();
    CPU cpu1(s3,s4);
    cout<<"CPU 1:"; cpu1.Show();
    Computer computer0;
    cout<<"Computer0: ";     computer0.Show();
    Computer computer1(s1,s2,ram,price,s3,s4);
    cout<<"Computer1: ";     computer1.Show();
    Computer computer2(s1,s2,ram,price,cpu1);
    cout<<"Computer2: ";     computer2.Show();
    Computer computer3(s1,s2,ram,price);
    cout<<"Computer3: ";     computer3.Show();
    Computer computer4(cpu1);
    cout<<"Computer4: "; computer4.Show();
    return 0;
}