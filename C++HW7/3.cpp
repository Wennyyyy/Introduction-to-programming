#include <iostream>
#include <cstring>
#include <sstream>  
#include <ctype.h>
using namespace std;
void selectSort(int num,int *scores){
	int minIndex;
	double minElem;
	for (int scan = 0; scan < (num - 1); scan++){
		minIndex = scan;
		minElem = *(scores+scan);
		for(int i = scan + 1; i < num; i++)
		{
			if (*(scores + i) < minElem)
			{
				minElem = *(scores + i);
				minIndex = i;
			}
		}
		scores[minIndex] = scores[scan];
		*(scores+scan) = minElem;
	}
}
int median(int a[], int n){
	if(n % 2 !=0){
		return a[n / 2];
	}
	else
		return (a[n / 2] + a[n / 2 - 1]) / 2;
}
bool isNum(string str)  
{  
	stringstream sin(str);  
	int d;  
	char c;
	if(!(sin >> d)){
		return false;
	}
	if (sin >> c){
		return false;
	}  
	return true;  
}
int mode(int a[], int n){
    int cnt = 0, maxcnt = 0,index = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (a[j] == a[i])
                cnt++;
        }
        if(cnt > maxcnt){
            maxcnt=cnt;
            index = i;
        }
        cnt = 0;
    }
    return a[index];
}
int main(int argc,char* argv[]){
    int * pies;
    string input;
    stringstream ss;
    int myint;
    pies = new int[30];
    for (int i = 0; i < 30; i++){
        do {
            cout<<"Enter the number of pies u ate in a year : ";
            getline(cin, input);
            if(!isNum(input) ){
                i--;
                cout<<"U should enter nonnegative number."<<endl;
                myint = 0;
                break;
            }
            ss<< input;
            ss>> myint;
            ss.clear();
            if(myint < 0 ){
                i--;
                cout<<"U should enter nonnegative number."<<endl;
                myint = 0;
                break;
            }
            else{
                pies[i] = myint;
                break;
            }
        }while(myint >= 0 && isNum(input));
    }
    selectSort(30, pies);
    cout<<"\nThe pies people consumed after sorted: \n";
    for (int i = 0; i < 30; i++){
        cout<<pies[i]<<" ";
        if((i+1)%10 == 0){
            cout<<endl;
            i-1;
        }
    }
    cout<<"The median of the pies: "<<median(pies, 30)<<endl;
    cout<<"The mode of the pies: "<<mode(pies, 30)<<endl;
    delete[] pies;
    return 0;
}