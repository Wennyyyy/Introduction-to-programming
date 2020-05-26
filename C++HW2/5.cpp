#include<iostream>
using namespace std;
char a[7][8]={};
//1 3 5 7 5 3 1 a[i][j]
int main(){
    int d=1;
    for(int i=0;i<7;i++){
        for(int j=0;j<8;j++){
            a[i][j]='+';
            if (j==7) a[i][j]='\n';
            else if (!(i%6)&&j!=0) a[i][j]=' ';
            else if (i%2&&j>2&&i!=3) a[i][j]=' ';
            else if (i%3&&j>4) a[i][j]=' ';
        }
    }
    for(int i=0;i<7;i++){
        for (int j=0;j<8;j++){
          cout<<a[i][j];
        }
    }
    return 0;
}
            //if(i>=j) a[i][j]='+';
            //else a[i][j]=' ';
            //if((i+j)>6) a[i][j]=' ';
