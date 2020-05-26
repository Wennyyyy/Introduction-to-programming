#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    char name[20],package;
    double time;
    cout<<"Please enter your name: ";
    cin>>name;
    do{
        cout<<"Which package did you purchase?(Enter A-C) ";
        cin>>package;
    } while (package != 'A'&&package != 'B'&&package != 'C');
    cout<<"how many hours did you used?(in hours) ";
    cin>>time;
    if(package=='A'){
        double amountA;
        if (time>5) amountA = 9.95+(time-5)*60*0.08;
        else amountA = 9.95;
        cout<<"User name: "<<setw(27)<<right<<name<<endl;
        cout<<"Usage hours: "<<setw(25)<<right<<time<<endl;
        cout<<"Total amount due: "<<setw(15)<<"$"<<right<<amountA<<endl;
    }
    else if(package=='B'){
        double amountB;
        if (time>10) amountB = 14.95+(time-10)*60*0.06;
        else amountB = 14.95;
        cout<<"User name: "<<setw(27)<<right<<name<<endl;
        cout<<"Usage hours: "<<setw(25)<<right<<time<<endl;
        cout<<"Total amount due: "<<setw(15)<<"$"<<right<<amountB<<endl;
    }
    else{
        const double amountC=19.95;
        cout<<"User name: "<<setw(27)<<right<<name<<endl;
        cout<<"Usage hours: "<<setw(25)<<right<<time<<endl;
        cout<<"Total amount due: "<<setw(15)<<"$"<<right<<amountC<<endl;
    }
    return 0;
}
