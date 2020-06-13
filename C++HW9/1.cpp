#include <iostream>
#include <iomanip>
#include <string.h>
#include <sstream>
using namespace std;
class Number{
    private:
        double number;
        const string lessThan20[20] = {
            "zero", "one", "two", "three", "four", "five", "six", "seven", 
            "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
            "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
        const string ty[10] = {"", "", 
            "twenty", "thirty", "forty", "fifty", 
            "sixty", "seventy", "eighty", "ninety" };
        const string hundred = "hundred";
        const string thousand = "thousand";
    public:
    Number(double num){
        this->number = num;
    }
    string translate(double fnum){
        int num = fnum;
        string rtn;
        double F = fnum - num;
        int S = num%10, T = (num%100 - S)/10;
        int Th = (num%10000 - num%1000)/1000, H = (num%1000 - T)/100;
        if( Th > 0){
            rtn += this->lessThan20[Th];
            rtn += " ";
            rtn += this->thousand;
            rtn += " ";
        }
        if( H > 0){
            rtn += this->lessThan20[H];
            rtn += " ";
            rtn += this->hundred;
            rtn += " ";
        }
        if( T > 0){
            if( T >= 2){
                rtn += this->ty[T];
                rtn += " ";
            }
            else {
                rtn += this->lessThan20[num%100];
                rtn += " ";
            }
        }
        if(S > 0){
            rtn += lessThan20[S];
            rtn += " ";
        }
        if(F > 0){
            int f = F*100;
            string numf;
            stringstream ss;
            ss<<f;
            ss>> numf;
            ss.clear();
            rtn += "and " + numf + " cents\n";
        }
        return rtn;
    }
};

int main(int argc, char* argv[]){
    double num = -1;
    string  date, name;
    cout<<"Please enther the date. ( DD/MM/YYYY )  ";
    getline(cin,date);
    cout<<"Please enter the payee's name. ";
    getline(cin,name);
    while(num<0||num>10000){
        cout<<"Please enter the amount of the check. ( <10000 )  ";
        cin>>num;
        cout<<endl;
    }
    Number number(num);
    cout<<"                         Date: "<<date<<endl;
    cout<<"Pay to the Order of:     "<<name<<"     $"
        <<fixed<<setprecision(2)<<num<<endl;
    cout<<number.translate(num)<<endl;
    return 0;
}