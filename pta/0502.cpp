#include <iostream>
#include <vector>
using namespace std;

class person {
    private:
    string name;
    int sex;
    public:
    person() : name("NULL"), sex(-1) {}
    person(const string& name, int sex) : name(name), sex(sex) {}
    person(const person& p) : name(p.name), sex(p.sex) {}
    int getSex() { return sex; }
    void setSex(int num) { sex = num; }
    string& getName() { return name; }
};

int main() {
    int num, sex; cin >> num;
    string name;
    vector<person> p_group;
    for(int i = 0; i < num; ++i) {
        cin >> sex >> name;
        p_group.emplace_back(name, sex);
    }
    for(int i = 0; i < num / 2; ++i) {
        for(int j = num - 1; j >= num / 2; --j) {
            if(p_group[i].getSex() + p_group[j].getSex() == 1) {
                cout << p_group[i].getName() << " " << p_group[j].getName() << endl;
                p_group[i].setSex(-1); p_group[j].setSex(-1);
                break;
            }
        }
    }
    return 0;
}