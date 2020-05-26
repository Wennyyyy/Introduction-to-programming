#include <iostream>
#include <string>
#include <sstream>
#include <time.h> 
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]){
    int winningDigits[5],player[5];
    string s;
    bool flag=1;
    int matchNum;
    
    char isgame;
    srand( time(NULL) );
    do{
        for(int i=0;i<5;i++){
            winningDigits[i]=rand() % 10;
        }

        bool cont = 1;
        while(cont){
            cout<<"Please enter ur lucky number:";
            getline(cin,s);
            if(s.size() == 5) {
                cont = 0;
                for(int i = 0; i < 5; i++){
                    if(s[i]<'0' || s[i]>'9') cont = 1;
                    player[i] = s[i] - '0';
                }
            }
            if(cont){
                cout<<"Wrong input, do it again.\n";                      
            }
        }

        cout << endl;
        cout << "winningDigits:";
        for(int i = 0; i<5; ++i){
            cout << winningDigits[i] << " ";
        }
        cout << endl;

        cout << "player:       ";
        for(int i = 0; i<5; ++i){
            cout << player[i] << " ";
        }
        cout << endl;

        matchNum = 0;
        for(int i = 0; i<5 ; ++i){
            if(winningDigits[i] == player[i]) matchNum++;
        }

        cout << "You match " << matchNum << " number\n\n";

        
        cout<<"Do u want to Quit?\n";
        cout<<"Enter Q to quit or press any other key.\n";
        getline(cin,s);
        isgame = s[0];
        if(isgame=='Q') flag =0;
        else flag=1;
    } while (flag);
    return 0;
}