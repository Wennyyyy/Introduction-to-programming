#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

int linearSearch(const int array[], int size, int value){
	int index = 0; 		
	int position = -1; 	
    int counter = 0;
	bool found = false; 
	while (index < size && !found){
		if (array[index] == value){
			found = true; 	
			position = index;
		}
		index++;
        counter++;
	}
	return counter;
}

int binarySearch(const int array[], int size, int value){
	int first = 0, last = size - 1,	middle, position = -1;
    int counter=0;
	bool found = false; 
	while (!found && first <= last){
		middle = (first + last) / 2; 	
		if (array[middle] == value){
			found = true;
			position = middle;
		}
		else if (array[middle] > value) 	
			last = middle - 1;
		else
			first = middle + 1; 
        counter++;
	}
	return counter;
}

int main(int argc,char* argv[]){
    srand(time(NULL));
    const int MAX=30;
    int sum1=0,sum2=0,guess=0;
    int random1[MAX]={0};
    for(int i=0; i<20; i++){
        for(int j=0; j<MAX; j++){
            random1[j] = rand();   
        }
        guess = random1[rand()%MAX];
        sort( random1, random1+MAX );
        int count1 = linearSearch( random1, MAX, guess);
        sum1 += count1;
        int count2 = binarySearch( random1, MAX, guess);
        sum2 += count2;
        cout<<setw(2)<<i<<". Linear Search : "
            <<count1<<"/ Binary Search : "<<count2<<endl;
    }
    cout<<setfill('=')<<setw(17)<<right<<"Average"<<setw(10)<<"\n";
    cout<<setfill(' ')<<"Linear Search : "<<setw(10)<<right<<sum1/20<<endl
        <<"Binary Search : "<<setw(10)<<right<<sum2/20<<endl;
    return 0;
}