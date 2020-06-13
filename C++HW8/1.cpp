#include <iostream>
#include <string.h>
using namespace std;
class Number{
    private:
        int number;
        string lessThan20[20] = {
            "zero", "one", "two", "three", "four", "five", "six", "seven", 
            "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
            "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
        string ty[10] = {"", "", 
            "twenty", "thirty", "forty", "fifty", 
            "sixty", "seventy", "eighty", "ninety" };
        string hundred = "hundred";
        string thousand = "thousand";
    public:
    Number(int num){
        this->number = num;
    }
    string translate(int num){
        string rtn;
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
                return rtn;
            }
        }
        if(S > 0){
            rtn += lessThan20[S];
            rtn += " ";
        } 
        return rtn;
    }
};

int main(int argc, char* argv[]){
    int num = -1;
    while(num<0||num>9999){
        cout<<"Please enter a number. (0~9999)  ";
        cin>>num;
        cout<<endl;
    }
    Number number(num);
    cout<<number.translate(num)<<endl;
    return 0;
}