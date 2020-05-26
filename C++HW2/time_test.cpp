#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using  namespace std;
int main(){
    time_t a,b,c,d,e=10;
    a=time(NULL);
    Sleep(1000);
    b=time(NULL);
    c=time(0);
    e=time(&e);
    cout<<"a: "<<ctime(&a)<<endl;
    cout<<"b: "<<ctime(&b)<<endl
        <<"c: "<<ctime(&c)<<endl
        <<"d: "<<ctime(&d)<<endl
        <<"e: "<<ctime(&e)<<endl;

    return 0;
}
