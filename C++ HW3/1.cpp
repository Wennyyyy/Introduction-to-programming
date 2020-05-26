#include <iostream>
#include <iomanip>
using namespace std;

double Celsius (double Temperature){
    return (Temperature-32)*5/9;

}
int main(){
    cout<<"               Temperature Convert Table:"<<endl;
    for(int j=0;j<65;j++) cout<<"_";
    cout<<endl;
    for (int i=0;i<=20;i++)
    {
        cout<<setw(7)<<right<<i<<" degree Fahrenheit "<<setw(5)
        <<left<<"is equal to ";
        double degree_celsius=Celsius(i);
        cout<<setw(10)<<right<<degree_celsius<<" degree Celsius."<<endl;
    }
}
