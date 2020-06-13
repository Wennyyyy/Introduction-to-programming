#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
string binsDescription[9] = {"Turkey", "Chocolate", "Egg", "Yoyo",
                             "ChickenBreast", "Gummy Bear", "Almond",
                             "Cookie", "Spaghetti" };
class InvBin{
    private:
        string description;     // Item name 
        int qty;                // Quantity of items
                                // in this bin
    public:
        InvBin (string d = "empty", int q= 0){
            // 2-parameter constructor
            // with default values
            description= d;
            qty= q;
        }
        // It will also have the following public member functions. They
        // will be used by the BinManager class, not the client program.
        void setDescription(string d){
            this->description = d;
        }
        string getDescription(){
            return this->description;
        }
        void setQty(int q){
            this->qty = q;
        }
        int getQty(){
            return this->qty;
        }
};

class BinManager{
    private:
        InvBin *bin;
        int numBins;
    public:
        BinManager(){
            numBins = 0;
        }
        BinManager(int size, string d[], int q[]){
            bin = new InvBin[30];
            this -> numBins = size;
            for(int i=0; i<size; i++){
                bin[i].setDescription(d[i]);
                bin[i].setQty(q[i]);
            }
        }
        ~BinManager(){
            delete []bin;
        }
        string getDescription(int index){
            return this->bin[index].getDescription();
        }     
        int getQuantity(string itemDescription){  
            int index = this->search(itemDescription);
            return this->bin[index].getQty();
        }            
        bool addParts(string itemDescription, int q){
            int binIndex = this->search(itemDescription);
            if(q<1 || binIndex>=this->numBins || binIndex<0) return false;                                
            this->bin[binIndex].setQty(this->bin[binIndex].getQty() + q);   
            return true;
        }    
        bool removeParts(string itemDescription, int g){       
            int binIndex = this->search(itemDescription);       
            if(g<1 || binIndex>=this->numBins || binIndex<0) return false;   
            int newQty = this->bin[binIndex].getQty() - g; 
            if(newQty >= 0){                               
                this->bin[binIndex].setQty(newQty);    
                return true;
            } else {
                return false;
            }
        }
        int search(string itemDescription){
            for(int i=0; i<9; i++){
                if( itemDescription == binsDescription[i] ){
                    return i;
                }
            }
            return -1;
        }                                                            
        int getnumBins(){
            return this->numBins;
        }
};
int getInt(){
    string sin;
    int num;
    getline(cin,sin);
    stringstream ss(sin);
    while(true){
        char ischar;
        if( ss >> num){
            if(!(ss >> ischar)){
                break;
            }
        }
        cout<<"You should input integer."<<endl;
        getline(cin,sin);
        ss.clear();
        ss << sin;
    }
    return num;
}
void displayReport(BinManager &binManager){
    int numBins = binManager.getnumBins();
    cout<<endl
        <<left<<setw(20)<<"Bin description"
        <<left<<setw(22)<<"Bin Quantity"<<endl;
    for(int i = 0; i < numBins; i++){
        cout<<right<<setw(2)<<i<<"."
            <<left<<setw(20)<<binManager.getDescription(i)
            <<left<<setw(22)<<binManager.getQuantity(binsDescription[i])<<endl;
    }
}

int main(int argc, char* argv[]){
    int binsQty[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};     
    BinManager binManager(9, binsDescription, binsQty);
    string sin;
    int indexSelect, num;
    while(true){
        displayReport(binManager);
        cout<<"\nWhat do U want to do?(Add/Remove/Quit)"<<endl;
        getline(cin,sin);
        if(sin == "Add"){
            cout<<"Which one do U want to add?(name)"<<endl;
            getline(cin,sin);
            cout<<"How many?"<<endl;
            num = getInt();
            if(!binManager.addParts(sin, num)){
                if(num < 0) cout<<"U can't enter negative number."<<endl;
                else cout<<"Wrong Index. \n";
            }
        } else if(sin == "Remove") {
            cout<<"Which one do U want to remove?(name)"<<endl;
            getline(cin,sin);
            cout<<"How many?"<<endl;
            num = getInt();
            if(!binManager.removeParts(sin, num)){
                if(num >binManager.getQuantity(sin)) cout<<"No enough quantity to remove.\n";
                else cout<<"Wrong name. "<<endl;
            }
        } else if(sin == "Quit") {
            cout<<"\n================Bin Manager================";
            break;
        } else {
            cout<<"I don't understand what U mean * A * ! \n";
        }
    }

    displayReport(binManager);
    return 0;
}