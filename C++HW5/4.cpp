#include <iostream>
#include <sstream>
using namespace std;

class Stats{
    private:
        string city;
        string monthYear;
        double rainfall[30];
        int cnt;
        int most, least;
        const string month[12]={  "January", "February", "March",
                            "April", "May", "June", "July",
                            "August","September","October",
                            "November","December"
                         };
    public:
        Stats(string city, string monthYear){
            this -> city = city;
            this -> monthYear = monthYear;  
            for(int i=0; i<30; i++) this -> rainfall[i] = 0;
            this -> cnt = 0;
            this -> most = 0;
            this -> least = 0;
        }
        double total(){
            double sum = 0;
            for(int i=0; i< this->cnt; i++){
                sum += this->rainfall[i];
            }
            return sum;
        }
        double average(){
            return this->total()/this->cnt;
        }
        double lowest(){
            double L=rainfall[0];
            for(int i=0; i< this->cnt; i++){
                if(this->rainfall[i] < L){
                    least = i;
                    L = this->rainfall[i]; 
                }
            }
            return L;
        }
        double highest(){
            double M=rainfall[0];
            for(int i=0; i< this->cnt; i++){
                if(this->rainfall[i] > M){
                    most = i;
                    M = this->rainfall[i];
                } 
            }
            return M;
        }
        bool storeValue(double rainfall){
            if (rainfall<0 || cnt>30) return false;
            this->rainfall[this->cnt] = rainfall;
            cnt++;
            return true;
        }
        string convert(){
            stringstream ss;
            int monthnum;
            
            ss << this->monthYear.substr(4,2);
            ss >> monthnum;
            return this->month[monthnum] + ", " + this->monthYear.substr(0,4);
        }

        string convert(int cnt){
            stringstream ss;
            int monthnum, yearnum;
            string yearstr;
            
            ss << this->monthYear.substr(4,2);
            ss >> monthnum;
            ss.clear();

            ss << this->monthYear.substr(0,4);
            ss >> yearnum;
            ss.clear();

            yearnum += (monthnum + cnt)/12;
            monthnum = (monthnum + cnt)%12;

            ss << yearnum;
            ss >> yearstr;

            return this->month[monthnum] + ", " + yearstr;
        }

        string displayReport(){
            string ret;
            ret += this->convert() + " -" + this->convert(cnt) + " Rain Report for " + this->city +"County\n";
            stringstream temp;
            string strtemp;
            temp<< total();
            temp>> strtemp;
            temp.clear();
            ret += "Total rainfall in this period: " + strtemp + " inches\n";
            temp<< average();
            temp>> strtemp;
            temp.clear();
            ret += "Average monthly rainfall: " + strtemp + " inches\n";
            temp<< lowest();
            temp>> strtemp;
            temp.clear();
            ret += "The least rain fell in " + this->convert(least) + " with " + strtemp + " inches\n";
            temp<< highest();
            temp>> strtemp;
            temp.clear();
            ret += "The most rain fell in " + this->convert(most) + " with " + strtemp + " inches\n";
            return ret;
        }
};
int main (int argc, char* argv[]){
    string city,monthYear;
    double rainfall;
    int cont;
    string s;
    char c;

    cout<<"Please enter the city u want to analyze:";
    getline(cin,city);
    cout<<"Please enter the month u started to analyze:";
    cin>> monthYear;
    Stats stats(city, monthYear); 

    cont = 1;
    while(cont){
        do{
            cout<<"\nHow's the rainfall in "<<city<<" ?\n";
            cin>>rainfall;
        }while(!stats.storeValue(rainfall));
        getline(cin,s);

        do{
            cout<<"Do u want to continue?\n";
            cout<<"Please enter Y/N only.\n";
            getline(cin,s);
            if(s[0]=='Y') cont =1;
            else cont = 0;
        }while(s.size()>1 || (s[0] != 'Y' && s[0] != 'N'));
    }
     
    cout<<stats.displayReport();
    return 0;
}