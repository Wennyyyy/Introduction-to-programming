#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;
int bubbleSort(int array[], int size){
	int temp, counter=0;
	bool swap;
	do{ 
        swap = false;
		for (int count = 0; count < (size - 1); count++){
			if (array[count] > array[count + 1]){
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
                counter++;
			}
		}
	} while (swap);
    return counter;
}

int selectionSort(int array[], int size){
	int start, minIndex, minValue, counter=0;
	for (start = 0; start < (size - 1); start++){
		minIndex = start;
		minValue = array[start];
		for (int index = start + 1; index < size; index++){
			if (array[index] < minValue){
				minValue = array[index];
				minIndex = index;
                counter++;
			}
		}
		array[minIndex] = array[start];
		array[start] = minValue;
	}
    return counter;
}

int main(int argc,char* argv[]){
    srand(time(NULL));
    const int MAX=30;
    int sum1=0,sum2=0;
    int random1[MAX]={0},random2[MAX]={0};
    for(int i=0; i<20; i++){
        for(int j=0; j<MAX; j++){
            random1[j] = rand();
            random2[j] = random1[j];
        }
        int count1 = selectionSort( random1, MAX);
        sum1 += count1;
        int count2 = bubbleSort( random2, MAX);
        sum2 += count2;
        cout<<setw(2)<<i<<". Sellection Sort : "
            <<count1<<"/ Bubble Sort : "<<count2<<endl;
    }
    cout<<setfill('=')<<setw(17)<<right<<"Average"<<setw(10)<<"\n";
    cout<<setfill(' ')<<"Sellection Sort : "<<setw(8)<<right<<sum1/20<<endl
        <<"Bubble Sort : "<<setw(12)<<right<<sum2/20<<endl;
    return 0;
}