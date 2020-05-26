#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
class Vendingmachine{
    private:
    double sum;
    struct {
        string drink;
        double cost;
        int numInmachine;
    } vendingmachine[5];

    double inputMoney(int drinkIndx){
        double money = -1;
        string sin;
        while(money < 0){
            cout<<"Please input money."<<endl;
            getline(cin,sin);
            stringstream ss(sin);
            if(ss >> money ) {
                char ischar;
                if (!(ss >> ischar)){
                    if(money>0){
                        break;
                    }
                }
            }
            cout<<"You should input nonnegative number.\n"<<endl;
        }
        return money;
    }
    void dailyReport(){
        cout<<endl
            <<left<<setw(20)<<"Drink Name"
            <<left<<setw(22)<<"Number in machine"<<endl;
        for(int i=0; i<5; i++){
            cout<<left<<setw(20)<<this->vendingmachine[i].drink
                <<left<<setw(22)<<this->vendingmachine[i].numInmachine<<"\n";
        }
        cout<<endl;
        cout<<"!!$ Money made today is : "<<fixed<<setprecision(2)<<this->sum<<"$. $!!"<<endl;
        
    }
    public:
    Vendingmachine(){
        
        this->vendingmachine[0].drink = "Cola";
        this->vendingmachine[1].drink = "Root beer";
        this->vendingmachine[2].drink = "Orange soda";
        this->vendingmachine[3].drink = "Grape soda";
        this->vendingmachine[4].drink = "Bottled water";
        for(int i=0; i<5; i++){
            this->vendingmachine[i].cost = 1.00;
            this->vendingmachine[i].numInmachine = 20;
        }
        this->vendingmachine[4].cost = 1.50;
        this->sum  = 0;
    }
    ~Vendingmachine(){
        dailyReport();
    }
    void displayChoices(){
        cout<<left<<setw(20)<<"Drink Name"
            <<left<<setw(15)<<"Cost"
            <<left<<setw(15)<<"Number in machine\n";
        for(int i=0; i<5; i++){
            cout<<left<<setw(20)<<this->vendingmachine[i].drink
                <<left<<setw(22)<<fixed<<setprecision(2)<<this->vendingmachine[i].cost
                <<left<<setw(15)<<this->vendingmachine[i].numInmachine<<"\n";
        }
    }
    void buyDrink(){
        string sin;
        bool cont=1;
        int i;
        while(cont){
            cout<<"Which drink do u want to buy?";
            getline(cin,sin);
            for(i=0; i<5; i++){
                if (vendingmachine[i].drink == sin){
                    cont=0;
                    break;
                }
            }
            if (cont) cout<<"Please enter drinks on the menu.\n";
        }
        double money = inputMoney(i);
        if( money < vendingmachine[i].cost){
            cout<<"Your money isn't enough. QQ"<<endl;
            cout<<"Return money: "<< money<<endl;
        }
        else {
            if( this->vendingmachine[i].numInmachine <= 0 ){
                cout<<vendingmachine[i].drink<<" Sold out !!!"<<endl;
            }
            else {
                cout<<"Here is ur bevarage : "<<vendingmachine[i].drink<<endl;
                this->vendingmachine[i].numInmachine --;
                this ->sum += this->vendingmachine[i].cost;
                cout<<"Return money: "<< money-this->vendingmachine[i].cost<<endl;
            }
        }
        cout<<endl;
    }
};
int main(int argv,char* argc[]){
    bool cont=1;
    Vendingmachine vendingmachine;
    string sin;
    while(true){
        vendingmachine.displayChoices();
        do{
            cout<<"Do u want to buy a drink? (Y/N)";
            getline(cin,sin);
            if(sin[0]=='Y') cont =1;
            else cont = 0;
        }while(sin.size()>1 || (sin[0] != 'Y' && sin[0] != 'N'));
        if( cont==0 ) break;
        vendingmachine.buyDrink();
    }
    return 0;
}