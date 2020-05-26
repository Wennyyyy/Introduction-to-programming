#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
string salsa[]={"mild", "medium", "sweet", "hot","zesty"};
int sold[5]={0,0,0,0,0};

int main(){
    int jarnum=0,maxsold=0,maxindex=0,leastindex=0,leastsold=0,sum=0;
    bool startover;
    for(jarnum=0;jarnum<5;jarnum++){
        do{
            startover=0;
            cout<<"Please enter the jar sold of "<<salsa[jarnum]<<" : ";
            string input;
            getline(cin,input);
            stringstream num(input);
            if(!(num >> sold[jarnum] )) {
                cout<<"You should input nonnegative integer.\n"<<endl;
                startover=1;
            }
            char ischar;
            if (num >> ischar){
                cout<<"You should input nonnegative integer.\n"<<endl;
                startover=1;
            }
            if(sold[jarnum]<0){
                cout<<"You should input nonnegative integer.\n"<<endl;
                startover=1;
            }
            leastsold=sold[0];
            if (sold[jarnum]>=maxsold){ maxsold=sold[jarnum]; maxindex=jarnum; }
            if (sold[jarnum]<=leastsold){ leastsold=sold[jarnum]; leastindex=jarnum; }
        }while(startover);
    }
    cout<<endl<<"|"<<setfill('=')<<setw(40)<<"|"<<endl;
    for(jarnum=0;jarnum<5;jarnum++){
        cout<<"  The jar sold of "<<setfill(' ')<<setw(10)<<salsa[jarnum]<<" is : "<<sold[jarnum]<<endl;
        sum+=sold[jarnum];
    }
    cout<<"  The total sold of salsa is "<<sum<<"."<<endl;
    cout<<"  The highest selling is "<<salsa[maxindex]<<"."<<endl;
    cout<<"  The lowest selling is "<<salsa[leastindex]<<"."<<endl;
    cout<<"|"<<setfill('=')<<setw(40)<<"|"<<endl;
    return 0;
}
