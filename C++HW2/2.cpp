#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    char name[20],package;
    double time;
    cout<<"To calculate how much money u can save:"<<endl;
    cout<<"Please enter your name: ";
    cin>>name;
    double amountA=0,amountB=0;
    const double amountC=19.95;
    do{
        cout<<"Which package did you purchase?(Enter A-C) ";
        cin>>package;
    } while (package != 'A'&&package != 'B'&&package != 'C');
    cout<<"how many hours did you used?(in hours) ";
    cin>>time;
    if (time>5) amountA = 9.95+(time-5)*60*0.08;
    else amountA = 9.95;
    if (time>10) amountB = 14.95+(time-10)*60*0.06;
    else amountB = 14.95;
    if(package=='A'){
            if (amountA>amountB){
                cout<<"You can save $"<<setw(10)<<left<<amountA-amountB<<" by choosing package B."<<endl;
            }
            if (amountA>amountC){
                cout<<"You can save $"<<setw(10)<<left<<amountA-amountC<<" by choosing package C."<<endl;
            }
    }
    else if(package=='B'){
            if (amountB>amountC){
                cout<<"You can save $"<<setw(10)<<left<<amountB-amountC<<" by choosing package C."<<endl;
            }
    }
    else{}

    return 0;
}
