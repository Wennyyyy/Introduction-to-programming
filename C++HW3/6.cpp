#include <iostream>
#include <iomanip>
using namespace std;

double population(double P,double B, double D){
    return  P*(1 + B)*(1 - D);
}
double update_population(double initialP,int y){
    static int arrivals,departures;
    do{
        cout<<"How many people move into this area in year "<<y<<" ? ";
        cin>>arrivals;
    }while(arrivals<0);
    do{
        cout<<"How many people leave this area in year "<<y<<" ? ";
        cin>>departures;
    }while(departures<0);
    return initialP+arrivals-departures;
}
int main(){
    double start_size;
    static double birth_rate,death_rate,years;
    do{
        cout<<"How many years from now do u want to know about the population? ";
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
    int y=1;double Newpopulation=start_size;
    while(years--){
        Newpopulation=population(Newpopulation,birth_rate,death_rate);
        Newpopulation=update_population(Newpopulation,y);
        y++;
    }
    cout<<"The population will be "<<int(Newpopulation)
    <<" after "<<y-1<<" years."<<endl;
    return 0;
}
