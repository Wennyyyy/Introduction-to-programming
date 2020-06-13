#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
string  wordSeperator(const char* c_string, int L){
    string rtn ;
    rtn += c_string[0];
    for(int i = 1; i < L; i++){
        if( isupper(c_string[i]) ){
            rtn += " ";
            rtn += tolower(c_string[i]);
        }
        else rtn += c_string[i];
    }
    return rtn;
}
int main(int argc, char* argv[]){
    string sin;
    cout<<"===== Word  Separator =====\n"
        <<"Enter ur sentence.\n";
    getline(cin,sin);
    cout<<"===========================\n";
    cout<<wordSeperator(sin.c_str(), sin.length())<<endl; 
    return 0;
}