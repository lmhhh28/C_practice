#include<iostream>
#include<iomanip>
using namespace std;

class Fixed_Deposit {
    private:
        double amount, rate, total;
        int year;
    public:
        Fixed_Deposit() {
            Set(10000, 0.033, 1);
        }
        Fixed_Deposit(double amounts, double rates, int years) {
            Set(amounts, rates, years);
        }
        void Set(double amounts, double rates, int years);
        double GetAmount();
        double GetRate();
        int GetYears();
        double GetAll();
        void Show();
};

void Fixed_Deposit::Set(double amounts, double rates, int years) {
    amount = amounts;
    rate = rates;
    year = years;
    total = amount + amount * year * rate;
}

double Fixed_Deposit::GetAmount() {
    return amount;
}

double Fixed_Deposit::GetRate() {
    return rate;
}

int Fixed_Deposit::GetYears() {
    return year;
}

double Fixed_Deposit::GetAll() {
    return total;
}

void Fixed_Deposit::Show() {
    cout<<"amount="<<GetAmount();
    cout<<"  rate="<<GetRate()*100<<"%";
    cout<<"  years="<<GetYears();
    cout<<"  total="<<GetAll()<<endl;
}

int main()
{
    cout<<fixed<<setprecision(2);
    Fixed_Deposit f1;
    cout<<"Show object f1:"<<endl;
    cout<<"amount="<<f1.GetAmount();        //输出存款本金
    cout<<"  rate="<<f1.GetRate()*100<<"%"; //输出存款利率
    cout<<"  years="<<f1.GetYears();        //输出存款年数
    cout<<"  total="<<f1.GetAll()<<endl;    //输出到期本息合计
    double amount,rate;
    int years;
    cin>>amount>>rate>>years;
    Fixed_Deposit f2(amount,rate,years);
    cout<<"Show object f2:"<<endl;
    cout<<"amount="<<f2.GetAmount();        //输出存款本金
    cout<<"  rate="<<f2.GetRate()*100<<"%"; //输出存款利率
    cout<<"  years="<<f2.GetYears();        //输出存款年数
    cout<<"  total="<<f2.GetAll()<<endl;    //输出到期本息合计
    cin>>amount>>rate>>years;
    cout<<"Reset and Show object f1:"<<endl;
    f1.Set(amount,rate,years);
    f1.Show();
    return 0;
}
