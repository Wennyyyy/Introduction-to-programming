#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;
class Rational{
    private:
        int num;
        int den;
        void reduce(){
            int gcd = this->gcd(abs(num), abs(den));
            num = num/gcd;
            den = den/gcd;
        }
        int gcd(int x, int y) { 
            int r = 0; 
            while(y != 0) { 
                r = x % y; 
                x = y; 
                y = r; 
            } 
            return x; 
        }
    public:
    Rational(int num, int den){
        this->num = num;
        this->den = den;
    }

    friend ostream& operator<<(ostream &os, const Rational &r) {
        return os << r.rational_to_string();
    }
    Rational operator+(const Rational &that) { 
        Rational rational(
            this->num * that.den + that.num * this->den,
            this->den * that.den
        );
        rational.reduce();
        return rational; 
    } 
    Rational operator-(const Rational &that) { 
        Rational rational(
            this->num * that.den - that.num * this->den,
            this->den * that.den
        );
        rational.reduce();
        return rational;
    } 
    Rational operator*(const Rational &that) { 
        Rational rational(
            this->num * that.num,
            this->den * that.den
        );
        rational.reduce();
        return rational;
    } 
    Rational operator/(const Rational &that) { 
        Rational rational(
            this->num * that.den,
            this->den * that.num
        );
        rational.reduce();
        return rational;
    } 
    string rational_to_string() const { 
        stringstream ss;
        string temp,rtn;
        ss<<this->num;
        ss>>temp;
        ss.clear();
        rtn += temp + "/";
        ss<<this->den;
        ss>>temp;
        ss.clear();
        return rtn + temp;
    }
};

int main(int argc, char* argv[]){
    int num;
    int den;
    char option, tmp;
    while(true){
        cout<<"input something:";
        cin>>num>>tmp>>den;
        Rational rational1(num, den);
        
        cin>>option;
        cin>>num>>tmp>>den;
        Rational rational2(num, den);
        if(option == '+')      cout<<"="<<(rational1 + rational2)<<endl;
        else if(option == '-') cout<<"="<<(rational1 - rational2)<<endl;
        else if(option == '*') cout<<"="<<(rational1 * rational2)<<endl;
        else if(option == '/') cout<<"="<<(rational1 / rational2)<<endl;
    }
    return 0;
}