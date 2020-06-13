#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
const string phoneNumberList[] = { 
    "Becky Warren, 678-1223",  "Joe Looney, 586-0097",
    "Geri Palmer, 223-8787",   "Bob Kain, 586-8712",
    "Holly Gaddis, 223-8878",  "Sam Wiggins, 486-0998",
    "Lynn Presnell, 887-1212", "Tim Haynes, 586-7676",
    "Warren Gaddis, 223-9037", "Jean James, 678-4939", 
    "Ron Palmer, 486-2783"   , "Tianna Wen, 520-1314"    };
string findPhoneNumberList(string find){
    string rtn;
    int sizeOfList = sizeof(phoneNumberList)/sizeof(string);
    for(int i = 0; i < sizeOfList; i++){
        string name = phoneNumberList[i].substr(0, phoneNumberList[i].find(",") - 1);
        if( name.find(find) != string::npos ) rtn += phoneNumberList[i] + "\n";
    }
    return rtn;
}
int main(int argc, char* argv[]){
    string sin, find, replace;
    cout<<"======= Phone Number List =========\n";
    cout<<"Enter the name part u want to find.\n";
    getline(cin,find);
    cout<<"===================================\n";
    cout<<findPhoneNumberList(find)<<endl;
    return 0;
}