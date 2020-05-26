#include <iostream>

using namespace std;
int num=600;
float in=21.77,out=16.44;

int main()
{
    cout << "The total amount paid for the stock: " <<num*in<< endl;
    cout << "The total amount received from selling the stock: " <<num*out<< endl;
    cout << "The total amount of money Kathryn lost: " <<num*(out-in)<< endl;
    return 0;
}
