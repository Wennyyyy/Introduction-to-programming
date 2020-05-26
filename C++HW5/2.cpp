#include<iostream>
#include<sstream>                                                                   //stringstream 調皮
#include<iomanip>
using namespace std;

string rightanswer = "BCCDCDADABABBDDAACCA";

class TestGrader{
    private:
        char answers[20];

    public:
        void setKey(string answers){
            for(int i = 0; i < answers.size() && i < 20; i++){
                this->answers[i] = answers[i];                                    //this-> sth in class(answers[20])
            }
        }
        string grade(char stdans[] ){
            int right=0,wrong=0;
            bool  wronglist[20],pass;
            string ret,strright,strwrong,list;
           
            for(int i = 0; i < 20; i++){
                if(this->answers[i] == stdans[i]){   
                    wronglist[i]=0;
                    right++;
                } else {
                    wronglist[i]=1;
                    wrong++;
                }
            }
            stringstream transfer;                                                  //I hate string QQ
            transfer << right;
            transfer >> strright;
            transfer.clear();
            transfer << wrong;
            transfer >> strwrong;
            transfer.clear();

            if(right>=15) ret += "Pass\n";
            else          ret += "Fail\n";
            ret += "Ur right answer is " + strright + ".\n" ;
            ret += "Ur wrong answer is " + strwrong + ".\n" ;
            ret +="Wrong number list: ";
            for(int i=0; i<20; i++){
                if (wronglist[i]){                                                  //I hate string again
                    transfer << i;
                    transfer >> list;
                    transfer.clear();
                    ret += list + " ";
                }
            }
            ret += "\n";
            return ret;
        }
};
int main(int argc, char* argv[]){
    TestGrader testGrader;
    testGrader.setKey(rightanswer);
    string s;
    bool flag=0;
    char answer[20];
    char isgame;
    do{
       
        for(int i=0;i<20;i++){
            while(true){
                cout<<"Please enter the answer for Q"<<i<<" :";
                getline(cin,s);
                answer[i] = s[0];
                if(s.size()>1 || answer[i]<'A' || answer[i]>'D'){ 
                    cout<<"Please enter A~D only.\n";
                } else {
                    break;
                }
            }
        }
        cout<<testGrader.grade(answer);
        do{
            cout<<"Do u want to continue?\n";
            cout<<"Please enter Y/N only.\n";
            getline(cin,s);
            isgame = s[0];
            if(isgame=='Y') flag =1;
            else flag=0;
        }while(s.size()>1 || (isgame != 'Y' && isgame != 'N'));
    } while (flag);

    return 0;
}