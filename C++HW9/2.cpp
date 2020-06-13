#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
int  wordCounter(const char* c_string, int L){
    int count = 0;
    for(int i = 0; i < L; i++){
        if( isalnum(c_string[i]) && !isalnum(c_string[i+1])) count++;
    }
    return count;
}
int main(int argc, char* argv[]){
    string sin;
    cout<<"===== How many words? =====\n"
        <<"Enter ur sentence.\n";
    getline(cin,sin);
    cout<<"===========================\n";
    cout<<"Words: "<<wordCounter(sin.c_str(), sin.length())<<endl;
    return 0;
}