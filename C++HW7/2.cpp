#include <iostream>
#include <iomanip>
#include <ctype.h>
using namespace std;
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
		scores[minIndex] = scores[scan];
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
    int num=0;
    double input=0;
    cout<<"Please enter the number of scores. ";
    cin>> num;
    double *scoreArray = new double[num];
    for (int i = 0; i < num; i++){
        do {
            cout<<"Enter the score: ";
            cin>> input;
            if(input<0){
                i--;
                cout<<"U should enter nonnegative number."<<endl;
                break;
            }
            else scoreArray[i] = input;
        }while(input >=0 && isdigit(input));
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
    cout<<"\n\nAverages:"<<setw(20)<<right<<avg<<endl;
    delete  [] scoreArray;
    return 0;
}
