#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;
class TicketManager{
    private:
        struct 
        {
            int price;
            bool isSold;
        }seatStructures[15][30];
        
    public:
        TicketManager(){
            fstream seatAvailability, seatPrices;
            seatAvailability.open("SeatAvailability.dat",ios::in);
            seatPrices.open("SeatPrices.dat",ios::in);
            int price;
            char availability;

            for(int i = 0; i<15; ++i){
                seatPrices >> price;
                for(int j = 0; j < 30; ++j){
                    seatAvailability >> availability;
                    this->seatStructures[i][j].price = price;
                    this->seatStructures[i][j].isSold = (availability == '*');
                }
            }

            seatAvailability.close();
            seatPrices.close();
        }
        ~TicketManager(){
            fstream seatAvailability;
            seatAvailability.open("SeatAvailability.dat",ios::out);

            for(int i = 0; i<15; ++i){
                for(int j = 0; j < 30; ++j){
                    if(this->seatStructures[i][j].isSold){
                        seatAvailability<<'*';
                    } else {
                        seatAvailability<<'#';
                    }
                }
                seatAvailability<<endl;
            }

            seatAvailability.close();
        }

        string getSeatChart(){
            stringstream ss;
            string temp;

            string ret = "";
            ret =  "                     Seats            \n";
            ret += "        123456789012345678901234567890\n";

            for(int i = 0; i < 15; ++i){
                ss<<i;
                ss>>temp;
                ss.clear();
                ret += "Row ";
                if(i<10) ret += " " + temp + "  ";
                else     ret += temp + "  ";
                for(int j = 0; j < 30; ++j){
                    if(this->seatStructures[i][j].isSold){
                        ret += "*";
                    } else {
                        ret += "#";
                    }
                }
                ret += "\n";
            }

            return ret;
        }        

        string tickRequest(vector<pair<int,int> > seats){
            stringstream ss;
            string stemp;

            bool errorLocation = false;
            int cost;
            string ret = "Your Seats:";
            for(int i = 0; i<seats.size(); ++i){
                if( (seats[i].first < 0 || seats[i].first >= 15 || seats[i].second < 0 || seats[i].second >=30 ) ||
                    (this->seatStructures[seats[i].first][seats[i].second].isSold) ){
                    errorLocation = true;
                } else {
                    ss << seats[i].first;
                    ss >> stemp;
                    ret += "(" + stemp;

                    ss << seats[i].second;
                    ss >> stemp;
                    ret += "," + stemp + ") ";

                    cost += this->seatStructures[seats[i].first][seats[i].second].price;
                }
            }

            if(errorLocation){
                return "Error LOcation\n";
            } else{
                ss << cost;
                ss >> stemp;
                ret += "\nTotal Cost:" + stemp + "\n";
                return ret;
            }


            return "";
        }

        string tickPurchase(vector<pair<int,int> > seats, int pay){
            stringstream ss;
            string stemp;

            int cost;
            string ret = "Your Seats:";
            for(int i = 0; i<seats.size(); ++i){
                ss << seats[i].first;
                ss >> stemp;
                ret += "(" + stemp;

                ss << seats[i].second;
                ss >> stemp;
                ret += "," + stemp + ") ";

                cost += this->seatStructures[seats[i].first][seats[i].second].price;
            }

            if(cost > pay){
                return "Insufficient pay!!!!!\n";
            } else{
                for(int i = 0; i<seats.size(); ++i) {
                    this->seatStructures[seats[i].first][seats[i].second].isSold = true;
                }
                ret += "\nSuccessfully paid.\n";
                return ret;
            }
        }

        string report(){
            stringstream ss;
            string temp;

            string ret = "";
            int soldNum = 0;
            int cllectMoney = 0;

            for(int i = 0; i < 15; ++i){
                for(int j = 0; j < 30; ++j){
                    if(this->seatStructures[i][j].isSold){
                        ++soldNum;
                        cllectMoney += this->seatStructures[i][j].price;
                    }
                }
            }

            ret = "Number of sold seat:     ";
            ss << soldNum;
            ss >> temp;
            ss.clear();
            ret += temp;
            ret += "\n";

            ret = "Number of available seat:";
            ss << ((15*30)-soldNum);
            ss >> temp;
            ss.clear();
            ret += temp;
            ret += "\n";

            ret = "Collected Money:         ";
            ss << cllectMoney;
            ss >> temp;
            ss.clear();
            ret += temp;
            ret += "\n";

            return ret;
        }


};
int main(int argc,char* argv[]){
    
    TicketManager ticketManager;

    bool cont = true;
    while(cont){
        int select = 0;
        
        cout<<endl
            <<setfill('=')<<setw(15)<<"Option"<<setw(15)<<"\n"
            <<"  0 :    Display the seating chart "<<endl
            <<"  1 :    Request tickets           "<<endl
            <<"  2 :    print sales report        "<<endl
            <<"  3 :    EXIT                      "<<endl;
        cin>>select;
        switch (select)
        {
        case 0: cout<<ticketManager.getSeatChart();
                break;
        case 1: {
                vector<pair<int,int> > seats;
                do{
                    int setI,setJ;
                    char cont;
                    
                    cout<<"Which seat do U want to buy?(example: 10 5)\n";
                    cout<<"Follow the format plz\n";
                    cin>>setI;
                    cin>>setJ;
                    pair<int, int> seat(setI,setJ);
                    seats.push_back(seat);

                    cout<<"More seat?(Y/N)\n";
                    cin>>cont;
                }while(cont == 'Y');
                string retMsg;
                retMsg = ticketManager.tickRequest(seats);
                cout << retMsg;
                if(retMsg != "Error LOcation\n"){
                    char purchase;
                    cout << "Are you sure to purchase?(Y/N) \n";
                    cin>>purchase;
                    if(purchase == 'Y'){
                        int pay;
                        cout << "Pay!!!!!\n";
                        cin >> pay;
                        cout << ticketManager.tickPurchase(seats, pay);
                    } else {
                        cout << "Ok! Fine!" << endl;
                    }
                }
                
                break;
        }       
        case 2: cout<<ticketManager.report();
                break;
        case 3: cont = false;
                break;
        
        default:
            cout<<"Wrong Input!"<<endl;
            break;
        }


    }

    
    return 0;
}