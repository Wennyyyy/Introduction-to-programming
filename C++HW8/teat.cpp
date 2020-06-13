#include <iostream>
#include <cstdlib>
using namespace std;

class Rational{
    private:
        int num;
        int denom;
        void reduce(){
            int gcd = this->gcd(abs(num), abs(denom));
            num = num/gcd;
            denom = denom/gcd;
        }
        int gcd(int m, int n) { 
            int r = 0; 

            while(n != 0) { 
                r = m % n; 
                m = n; 
                n = r; 
            } 

            return m; 
        }
    public:
    Rational(int num, int denom){
        this->num = num;
        this->denom = denom;
    }

    friend ostream& operator<<(ostream &os, const Rational &r) {
        return os << r.rational_to_string();
    }
    Rational operator+(const Rational &that) { 
        Rational rational(
            this->num * that.denom + that.num * this->denom,
            this->denom * that.denom
        );
        rational.reduce();
        return rational; 
    } 
    Rational operator-(const Rational &that) { 
        Rational rational(
            this->num * that.denom - that.num * this->denom,
            this->denom * that.denom
        );
        rational.reduce();
        return rational;
    } 
    Rational operator*(const Rational &that) { 
        Rational rational(
            this->num * that.num,
            this->denom * that.denom
        );
        rational.reduce();
        return rational;
    } 
    Rational operator/(const Rational &that) { 
        Rational rational(
            this->num * that.denom,
            this->denom * that.num
        );
        rational.reduce();
        return rational;
    } 
    string rational_to_string() const { 
        return to_string(this->num) + "/" + to_string(this->denom);
    }

};


int main(int argc, char* argv[]){
    int num;
    int denom;
    char c, tmp;
    while(true){
        cout<<"input something:";
        cin>>num>>tmp>>denom;
        Rational rational1(num, denom);
        cin>>c;
        cin>>num>>tmp>>denom;
        Rational rational2(num, denom);
        if(c == '+')      cout<<"="<<(rational1 + rational2)<<endl;
        else if(c == '-') cout<<"="<<(rational1 - rational2)<<endl;
        else if(c == '*') cout<<"="<<(rational1 * rational2)<<endl;
        else if(c == '/') cout<<"="<<(rational1 / rational2)<<endl;
    }
    return 0;
}