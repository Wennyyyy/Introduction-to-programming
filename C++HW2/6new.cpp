#include <iostream>
using namespace std;
double term(int N){
    if(N>=1) return term(N-1)/N;
    else return 1;
}
int main(){
    int i=1;   bool N=1;
    double result=0,L,Q;
    float limit;
    cout<<"Please enter a small (floating-point) number: ";
    cin>>limit;
    for(i=0;N;i++){
        L=term(i);
        if (i==0) cout<<"e = ";
        if (L>=limit) {
                if (i==0){
                        cout<<"1 + ";
                        result+=L;
                        continue;
                }
                cout<<"1/"<<i<<"!";
                if (i%10==0&&i) cout<<"    "<<endl;
                result+=L;
        }
        else {
                N=0;
                cout<<" = "<<result<<endl;
        }
        L=term(++i);  //check if there exists next term and print +
        if (L>=limit){
            cout<<" + ";
            i--;
        }
    }
    return 0;
}
