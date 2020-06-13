#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double future_value,annual_interest_rate;
int number_of_years;

double presentValue(double fvalue,double rate,int years){
    return fvalue/(pow(1+rate,years));
}
int main(){
    cout<<"Please enter the value you expect to draw : ";
    cin>>future_value;
    cout<<"Please enter the annual interest rate : ";
    cin>>annual_interest_rate;
    cout<<"Please enter number of years : ";
    cin>>number_of_years;
    double ans = presentValue(future_value,annual_interest_rate,number_of_years);
    cout<<"You should deposit the value of : "<<ans<<endl;

}
