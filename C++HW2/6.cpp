#include <iostream>
using namespace std;
long double multiple(int N){
    if(N>=1) return N*multiple(N-1);
    else return 1;
}
int main(){
    int i=1;
    bool N=1;
    long double result=1,L,Q;
    float limit;
    cout<<"Please enter a small (floating-point) number: ";
    cin>>limit;
    for(i=1;N;i++){
        Q=multiple(i);
        L=1/Q;
        if (i==1) cout<<"e = 1 + ";
        if (L>=limit) {
                cout<<"1/"<<i<<"! + ";
                if (i%10==0) cout<<"    "<<endl;
                result+=L;
        }
        else {
                N=0;
                result+=L;
                cout<<" 1/"<<i<<"! = "<<result<<endl;
        }
    }
    return 0;
}
