#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class person {
    private:
    string name, number;
    int birth;
    public:
    person() : name("NULL"), birth(0), number("0") {} 
    person(string& name, int birth, string& number)
    : name(name), birth(birth), number(number) {}
    person(const person& p) : name(p.name), birth(p.birth), number(p.number) {}
    
    void set(person& p) {
        name = p.name;
        number = p.number;
        birth = p.birth;
    }
    string& getName() { return name; }
    string& getNumber() { return number; }
    int getBrith() const { return birth; }
};

bool com(person& a, person& b) { return a.getBrith() < b.getBrith(); }

int main() {
    vector<person> p_group;
    string name, number;
    int num, birth;
    cin >> num;
    for(int i = 0; i < num; ++i) {
        cin >> name >> birth >> number; 
        p_group.emplace_back(name, birth, number);
    }
    // for(int i = 0; i < num; ++i) {
    //     for(int j = i + 1; j < num; ++j) {
    //         if(p_group[i].getBrith() > p_group[j].getBrith()) {
    //             person temp(p_group[i]);
    //             p_group[i].set(p_group[j]);
    //             p_group[j].set(temp);
    //         }
    //     }
    // }
    vector<person>::iterator begin = p_group.begin(), end = p_group.end();
    sort(begin, end, com);
    for(vector<person>::iterator it = begin; it != end; ++it) {
        cout << it -> getName() << " " << it -> getBrith() << " " << it -> getNumber() << endl;
    }
    return 0;
}