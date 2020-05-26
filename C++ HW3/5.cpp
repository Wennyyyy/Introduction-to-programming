#include <iostream>
#include <iomanip>
using namespace std;
double Newpopulation;

double population(double P,double B, double D){
    return  P*(1 + B)*(1 - D);
}

int main(){
    double start_size;
    static double birth_rate,death_rate,years;
    do{
        cout<<"The number of years to display : ";
        cin>>years ;
    }while(years<1);
    do{
        cout<<"The starting size of a population : ";
        cin>>start_size ;
    }while(start_size<2);
    do{
        cout<<"The annual birth rate : ";
        cin>>birth_rate ;
    }while ( birth_rate<0);
    do{
        cout<<"The annual death rate : ";
        cin>>death_rate ;
    }while ( death_rate<0);
     int y=1;
    while(years--){
            if (y==1){
                Newpopulation=population(start_size,birth_rate,death_rate);
                cout<<"The projected population at the end of year "<<y<<" : "
                <<setw(10)<<right<<Newpopulation<<endl;
            }
            if(y!=1){
                Newpopulation=population(Newpopulation,birth_rate,death_rate);
                cout<<"The projected population at the end of year "<<y<<" : "
                <<setw(10)<<right<<Newpopulation<<endl;
            }
            y++;
    }
    return 0;
}
