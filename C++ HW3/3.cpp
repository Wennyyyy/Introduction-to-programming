#include <iostream>
#include <iomanip>
using namespace std;
double ns,pp,pc,sp,sc;
double stockprofit(int NS,double PP,double PC,double SP,double SC){
    return ((NS*SP)-SC)-((NS*PP)+PC);
}
int main(){
    cout<<"Please enter the number of shares :";
    cin>>ns ;
    cout<<"Please enter the purchase price per share :";
    cin>>pp ;
    cout<<"Please enter the purchase commission paid :";
    cin>>pc ;
    cout<<"Please enter the sale price per share :";
    cin>>sp ;
    cout<<"Please enter sale commission paid :";
    cin>>sc ;
    double ans=stockprofit(ns,pp,pc,sp,sc);
    if(ans>=0) cout<<"The profit is "<<setw(10)<<left<<ans<<"."<<endl;
    else cout<<"The loss is "<<setw(10)<<left<<ans<<"."<<endl;
    return 0;
}
