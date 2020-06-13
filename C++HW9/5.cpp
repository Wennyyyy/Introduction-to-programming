#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
string passwordVerifier(const char* c_string, int L){
    string rtn ;
    bool hasLower = false, hasUpper = false,
         hasLength6 = false, hasDigit = false;
    for(int i = 0; i < L; i++){
        if( isupper(c_string[i]) ) hasUpper = true;
        if( islower(c_string[i]) ) hasLower = true;
        if( isdigit(c_string[i]) ) hasDigit = true;
    }
    if( L < 6 ) rtn += "Password lenth should be at least six.\n";
    if( !hasLower ) rtn += "Password should contain at least one lowercase.\n";
    if( !hasUpper ) rtn += "Password should contain at least one uppercase.\n";
    if( !hasDigit ) rtn += "Password should contain at least one digit.\n";
    if( L >= 6 && hasLower && hasLower && hasDigit ) rtn += "Successfully seted !!!\n";
    return rtn;
}
int main(int argc, char* argv[]){
    string sin;
    cout<<"===== Password Verifier =====\n"
        <<"Enter ur password.\n";
    getline(cin,sin);
    cout<<"=============================\n";
    cout<<passwordVerifier(sin.c_str(), sin.length())<<endl; 
    return 0;
}