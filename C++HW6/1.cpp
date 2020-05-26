#include <iostream>
#include <iomanip>
using namespace std;

bool strcompare(string a, string b){
    //return true, if a < b
    for(int i=0; i< min(a.length(), b.length()); i++){
       if(a[i] < b[i]) return true; 
       else if(a[i] > b[i])return false;
    }
    return ( a.length() < b.length() );
}

void selectionSort(string array[], int size){
	int 	start, minIndex;
    string  minValue;
	for (start = 0; start < (size - 1); start++){
		minIndex = start;
		minValue = array[start];
		for (int index = start + 1; index < size; index++){
			if (strcompare(array[index], minValue)){
				minValue = array[index];
				minIndex = index;
			}
		}
		array[minIndex] = array[start];
		array[start] = minValue;
	}
}

int main(int argc, char* argv[]){
    const int SIZE = 20;
    string name[SIZE] =
    {"Collins, Bill", "Smith, Bart", "Michalski, Joe", "Griffin, Jim",
    "Sanchez, Manny", "Rubin, Sarah", "Taylor, Tyrone", "Johnson, Jill",
    "Allison, Jeff", "Moreno, Juan", "Wolfe, Bill", "Whitman, Jean",
    "Moretti, Bella", "Wu, Hong", "Patel, Renee", "Harrison, Rose",
    "Smith, Cathy", "Conroy, Pat", "Kelly, Sean", "Holland, Beth"};
    // Insert your code to complete this program.
    selectionSort(name, SIZE);
    for (int i=0; i<SIZE; i++){
        cout<<setw(2)<<right<<i<<". "<<name[i]<<endl;
    }
    return 0;
}
