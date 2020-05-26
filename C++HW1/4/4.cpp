#include <iostream>
#include <iomanip>

using namespace std;
double num;
const double YEN_PER_DOLLAR=107.940,EUROS_PER_DOLLAR=0.899;

int main()
{
    cout << setprecision(3);
    cout << "Please enter the amount you want to convert (in US dollars): " ;
    cin >> num;
    cout << "Your amount from "<<right<< setw(10) <<fixed <<num <<" USD to :"<<endl;
    cout <<right<<setw(50)<<fixed<<num*YEN_PER_DOLLAR<<" JPY"<<endl;
    cout <<right<<setw(50)<<fixed<<num*EUROS_PER_DOLLAR<<" EUR"<<endl;
    return 0;
}
