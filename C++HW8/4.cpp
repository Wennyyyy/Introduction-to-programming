#include <iostream>
#include <iomanip>
using namespace std;
class DivSales{
    private:
        int season[4];
        int sum;
    public:
    DivSales(){
        int i=4;
        while(i--) this->season[i] = 0;
        this-> sum = 0;
    }
    void sales(int a, int b, int c, int d){
        season[0] = a;
        season[1] = b;
        season[2] = c;
        season[3] = d;
    }
    int getsales(int num){
        return season[num];
    }
    int getsum(){
         for(int i = 0; i < 4 ; i++){
                this->sum += this->season[i];
            }
        return this->sum;
    } 
};
int main(int argc, char* argv[]){
    DivSales divsales[6];
    int input[4];
    for(int i = 0; i < 6; i++){
        cout<<"==========division sale==========\n";
        cout<<"-              # "<<i+1<<"              -\n";
        for (int j = 0; j < 4; j++){
            cout<<"Sales for season "<<j+1<<": ";
            cin>>input[j];
        }
        cout<<"==================================\n";
        divsales[i].sales(input[0], input[1], input[2], input[3]);
    } 
    cout<<"\n=============Final report=============\n";
    for(int i = 0; i < 6; i++){
        cout<<"Division "<<i+1<<"  ";
        for (int j = 0; j < 4; j++){
            cout<<setw(5)<<divsales[i].getsales(j)<<" ";
        }
        cout<<"\n--------------------------------------\n";
    }
    int sum = 0;
    for(int i = 0; i < 6 ; i++){
        sum += divsales[i].getsum();
    }
    cout<<"The whole sales is "<<setw(7)<<sum<<endl;
    return 0;
}