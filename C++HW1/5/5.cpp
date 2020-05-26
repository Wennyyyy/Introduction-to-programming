#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int N;
double Rate,L,sum,Payment;
int main()
{
    cout << "What is the Amount of the loan? ";
    cin >> L;
    cout << "What is the monthly interest rate of the loan? (in %) ";
    cin >> Rate;
    cout << "Number of payments? ";
    cin >> N;

    Rate/=100;
    Payment=(Rate * pow(1 + Rate, N) / (pow(1 + Rate, N) - 1)) * L;
    Rate*=100;
    cout<<setprecision(2)<<endl;
    cout<<"Loan Amount: $ "<<left<<setw(10)<<fixed<<L<<endl;
    cout<<"Monthly Interest Rate: "<<setprecision(0)<<fixed<<Rate<<"%"<<endl;
    cout<<"Number of Payments: "<<N<<endl;
    cout<<setprecision(2);
    cout<<"Monthly Payment: $ "<<left<<setw(10)<<fixed<<Payment<<endl;
    cout<<"Amount Paid Back: $ "<<left<<setw(10)<<fixed<<Payment*N<<endl;
    cout<<"Interest Paid: $ "<<left<<setw(10)<<fixed<<Payment*N-L<<endl;
    return 0;
}
