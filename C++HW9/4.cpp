#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
string replaceSubstring(string str, string find, string replace){
    string rtn;
    int position;
    while((position = str.find(find)) != string::npos){
        rtn += str.substr(0,position);
        rtn += replace;
        str = str.substr(position + find.length());
    }
    rtn += str;
    return rtn;
}
int main(int argc, char* argv[]){
    string sin, find, replace;
    cout<<"===== Replace Substring  =====\n"
        <<"Enter ur sentence.\n";
    getline(cin,sin);
    cout<<"Enter the sentence u want to find.\n";
    getline(cin,find);
    cout<<"Enter the sentence u want to replace.\n";
    getline(cin,replace);
    cout<<"==============================\n";
    cout<<replaceSubstring(sin, find, replace)<<endl; 
    return 0;
}