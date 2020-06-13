#include <iostream>
using namespace std;

class Pstring : public string{
    private:

    public:
    Pstring() : string(){}
    Pstring(const char* s) : string(s){}
    Pstring(const string& str) : string(str){}
    bool isPalindrome(){
        int size = this->size()/2;
        for(int i = 0; i < size; i++) {
            if(this->operator[](i) != this->operator[](this->size() - 1 - i)) return false;
        }
        return true;
    }
};

int main(int argc, char* argv[]){
    Pstring pstring;
    string s;
    while(true) {
        cout << "Try to input something." << endl;
        getline(cin, pstring);
        if(pstring.isPalindrome()){
            cout << "It is Palindrome!!" << endl << endl;
        } else {
            cout << "It is not Palindrome!!" << endl << endl;
        }
    }
    return 0;
}