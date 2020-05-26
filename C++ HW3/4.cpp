#include <iostream>
#include <iomanip>
using namespace std;
double num,sum;

double stockprofit(int NS,double PP,double PC,double SP,double SC){
    return ((NS*SP)-SC)-((NS*PP)+PC);
}
void ask_data(){
    static double ns,pp,pc,sp,sc;
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
    int ans=stockprofit(ns,pp,pc,sp,sc);
    sum+=ans;
    if(ans>=0) cout<<"The profit is "<<ans<<" ."<<endl;
    else cout<<"The loss is "<<ans<<" ."<<endl;
}
int main(){
    cout<<"What is the number of stock sales? ";
    cin>>num;
    while(num--){
        ask_data();
    }
    cout<<"The total of the stocks ";
    if (sum>=0) cout<<"earned : "<<sum<<endl;
    else cout<<"lost : "<<sum<<endl;
    return 0;
}
