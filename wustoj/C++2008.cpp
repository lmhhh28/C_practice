#include<iostream>
using namespace std;

class Fraction {
    private:
        int nume, deno;
    public:
        Fraction() : nume(0), deno(1) {}
        Fraction(int numes, int denoes) : nume(numes), deno(denoes) {}
        Fraction(Fraction&& other) noexcept : nume(other.nume), deno(other.deno) {} 
        static int gcd(int a, int b) { return b ? gcd(b, a % b) : abs(a); }
        void appr() {
            int fractor = gcd(nume, deno);
            nume /= fractor;
            deno /= fractor;
        }
        Fraction& operator=(Fraction&& frac) {
            if(this != &frac) {
                nume = frac.nume;
                deno = frac.deno;
            }
            return *this;
        }
        friend istream& operator>>(istream& in, Fraction& frac);
        friend ostream& operator<<(ostream& os, Fraction& frac);
        friend Fraction operator+(Fraction& frac_1, Fraction& frac_2);
        friend Fraction operator-(Fraction& frac_1, Fraction& frac_2);
        friend Fraction operator*(Fraction& frac_1, Fraction& frac_2);
        friend Fraction operator/(Fraction& frac_1, Fraction& frac_2);
};

istream& operator>>(istream& in, Fraction& frac) {
    in >> frac.nume >> frac.deno;
    frac.appr();
    return in;
}

ostream& operator<<(ostream& os, Fraction& frac) {
    return os << frac.nume << '/' << frac.deno;
}

Fraction operator+(Fraction& frac_1, Fraction& frac_2) {
    int max_fractor = frac_1.deno * frac_2.deno / Fraction::gcd(frac_1.deno, frac_2.deno);
    int new_nume = frac_1.nume * max_fractor / frac_1.deno + frac_2.nume * max_fractor / frac_2.deno;
    int new_fractor = Fraction::gcd(new_nume, max_fractor);
    return move(Fraction(new_nume / new_fractor, max_fractor / new_fractor));
}

Fraction operator-(Fraction& frac_1, Fraction& frac_2) {
    Fraction temp(-frac_2.nume, frac_2.deno);
    return move(frac_1 + temp);
};

Fraction operator*(Fraction& frac_1, Fraction& frac_2) {
    int fractor_1 = Fraction::gcd(frac_1.nume, frac_2.deno);
    int fractor_2 = Fraction::gcd(frac_1.deno, frac_2.nume);
    return move(Fraction((frac_1.nume / fractor_1) * (frac_2.nume / fractor_2), (frac_1.deno / fractor_2) * (frac_2.deno / fractor_1)));
}

Fraction operator/(Fraction& frac_1, Fraction& frac_2) {
    Fraction temp(frac_2.deno, frac_2.nume);
    return move(frac_1 * temp);
}

int main()
{
    Fraction f1,f2,f3;
    cin>>f1>>f2;
    f3=f1+f2;
    cout<<f1<<" + "<<f2<<" = "<<f3<<endl;
    f3=f1-f2;
    cout<<f1<<" - "<<f2<<" = "<<f3<<endl;
    f3=f1*f2;
    cout<<f1<<" * "<<f2<<" = "<<f3<<endl;
    f3=f1/f2;
    cout<<f1<<" / "<<f2<<" = "<<f3<<endl;
    return 0;
}