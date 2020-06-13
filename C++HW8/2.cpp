#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class DayOfYear{
    private:
    int day;
    const string month[12]={"January", "February", "March",
                            "April", "May", "June", "July",
                            "August","September","October",
                            "November","December" };
    public:
    DayOfYear (int num){
        this -> day = num;
    }
    void print(int num){
        cout<<"Day "<<this->day<<" would be "<<this->transition(num)<<endl;
    }
    string transition(int num){
        string rtn;
        if (num<=31){
            stringstream ss;
            ss<<num;
            string date;
            ss>>date;
            ss.clear();
            rtn += month[0] + " " + date;
            return rtn;
        }
        if (num>31 && num<=59){
            stringstream ss;
            int cal = (num-31);
            ss<<cal;
            string date;
            ss>>date;
            ss.clear();
            rtn += month[1] + " " + date;
            return rtn;
        }
        if (num>59 && num<=90){
            stringstream ss;
            int cal = (num-59);
            ss<<cal;
            string date;
            ss>>date;
            ss.clear();
            rtn += month[2] + " " + date;
            return rtn;
        }
        if (num>90 && num<=120){
            stringstream ss;
            int cal = (num-90);
            ss<<cal;
            string date;
            ss>>date;
            ss.clear();
            rtn += month[3] + " " + date;
            return rtn;
        }
        if (num>120 && num<=151){
            stringstream ss;
            int cal = (num-120);
            ss<<cal;
            string date;
            ss>>date;
            ss.clear();
            rtn += month[4] + " " + date;
            return rtn;
        }
        if (num>151 && num<=181){
            stringstream ss;
            int cal = (num-151);
            ss<<cal;
            string date;
            ss>>date;
            ss.clear();
            rtn += month[5] + " " + date;
            return rtn;
        }
        if (num>181 && num<=212){
            stringstream ss;
            int cal = (num-181);
            ss<<cal;
            string date;
            ss>>date;
            ss.clear();
            rtn += month[6] + " " + date;
            return rtn;
        }
        if (num>212 && num<=243){
            stringstream ss;
            int cal = (num-212);
            ss<<cal;
            string date;
            ss>>date;
            ss.clear();
            rtn += month[7] + " " + date;
            return rtn;
        }
        if (num>243 && num<=273){
            stringstream ss;
            int cal = (num-243);
            ss<<cal;
            string date;
            ss>>date;
            ss.clear();
            rtn += month[8] + " " + date;
            return rtn;
        }
        if (num>273 && num<=304){
            stringstream ss;
            int cal = (num-273);
            ss<<cal;
            string date;
            ss>>date;
            ss.clear();
            rtn += month[9] + " " + date;
            return rtn;
        }
        if (num>304 && num<=334){
            stringstream ss;
            int cal = (num-304);
            ss<<cal;
            string date;
            ss>>date;
            ss.clear();
            rtn += month[10] + " " + date;
            return rtn;
        }
        if (num>334 && num<=365){
            stringstream ss;
            int cal = (num-334);
            ss<<cal;
            string date;
            ss>>date;
            ss.clear();
            rtn += month[11] + " " + date;
            return rtn;
        }
    }
};
int main(int argc, char* argv[]){
    int times,num;
    cout<<"Please enter how many times u want to transit. ";
    cin>>times;
    while(times--){
        cout<<"Enter the day u want to know: ";
        cin>>num;
        DayOfYear dayofyear(num);
        dayofyear.print(num);
    }
    return 0;
}