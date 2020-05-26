#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    int min=10,max=50,ans;
    char flag;
    bool game=1;
    cout<<"Start practice of adding two numbers:"<<endl;
    do{
        srand( time(NULL) );
        int q1 = rand() % (max - min + 1) + min;
        int q2 = rand() % (max - min + 1) + min;
        cout<<" "<<q1<<endl;
        cout<<"+"<<q2<<endl;
        cout<<"____"<<endl<<" ";
        cin>>ans;
        if(ans==q1+q2) cout<<"~~~congratulations~~~"<<endl;
        else cout<<"!!! the correct answer is "<<q1+q2<<"!!!"<<endl;
        do{
                cout<<"Do you want to continue the practice? (Y/N) ";
                cin>>flag;
            }while(flag!='Y'&&flag!='N');
       if (flag=='N') game=0;
    }while(game);
    return 0;
}
