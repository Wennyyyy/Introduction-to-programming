#include<iomanip>
#include<iostream>
using namespace std;
void f(int x, int &y, int& z);
   int main(){
      int a=10, b=20, c=30;
      f(a,b,c);
      cout << a << "  "   << b <<"  " << c << endl;
      return 0;
   }
   void f(int x, int &y, int& z){
      x += 1; y += 2; z += 3;
      cout << x << "  "<< y <<"  " << z << ",  ";
}
// 11  22 33, 10 22 33 *note: &y y difference
