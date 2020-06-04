#include <iostream>
#include <iomanip>
#include <ctype.h>
#include <sstream>  
#include <string>
using namespace std;
bool isNum(string str){  
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
void selectSort(int num,double *scores){
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
		*(scores+minIndex) = *(scores+scan);
		*(scores+scan) = minElem;
	}
}
double average(double* scores, int num){
    double sum;
    for (int i=0; i<num; i++) sum += *(scores+i) ;
    return sum/num;
}
void show(int num,double *scoreArray){
	for (int count = 0; count < num; count++)
		cout << scoreArray+count << " ";
	cout << endl;
}
int main(int argc, char *argv[]){
    int num=-1;
    double input=0;
    string sinput;
    stringstream ss;
    bool asknum = true;
    while(num < 0){
        ss.clear();
        cout<<"Please input the number of scores u want to record."<<endl;
        getline(cin,sinput);
        stringstream ss(sinput);
        if(ss >> num ) {
            if(num > 0){
                break;
            }
            else{
            cout<<"You should input nonnegative number."<<endl;
            num = -1;
            }
        }
        else{
            cout<<"You should input nonnegative number."<<endl;
            num = -1;
        }
    }
    ss.clear();
    double *scoreArray = new double[num];
    for (int i = 0; i < num; i++){
        do {
            ss.clear();
            cout<<"Enter the score: ";
            getline(cin,sinput);
            ss << sinput;
            ss >> input;
            if(input < 0 || !isNum(sinput)){
                i--;
                cout<<"U should enter nonnegative number."<<endl;
                ss.clear();
                break;
            }
            else{
                *(scoreArray+i) = input;
                break;
            }
        }while(input >=0 && isNum(sinput));
    }
    selectSort(num, scoreArray);
    double avg = average(scoreArray , num);
    cout<<"\nThe sorted scores: \n";
    for (int i = 0; i < num; i++){
        cout<<scoreArray[i]<<" ";
        if((i+1)%10 == 0){
            cout<<endl;
            i-1;
        }
    } 
    cout<<"\nAverages:"<<setw(20)<<right<<avg<<endl;
    delete  [] scoreArray;
    return 0;
}