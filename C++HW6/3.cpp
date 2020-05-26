#include <iostream>
using namespace std;

bool strcompare(string a, string b){
    //return true, if a < b
    for(int i=0; i< min(a.length(), b.length()); i++){
       if(a[i] < b[i]) return true; 
       else if(a[i] > b[i])return false;
    }
    return ( a.length() < b.length() );
}

int binarySearch(const string array[], int size, string value){
	int first = 0, 	
		last = size - 1,
		middle,			
		position = -1; 	
	bool found = false; 
	while (!found && first <= last){
		middle = (first + last) / 2; 	
		if (array[middle] == value) 	
		{
			found = true;
			position = middle;
		}
		else if (strcompare(value, array[middle]))
			last = middle - 1;
		else
			first = middle + 1; 
	}
	return position;
}

int main(int argc, char* argv[]){
    const int SIZE = 20;
    int ans;
    string search;
    string name[SIZE] ={
    "Allison, Jeff","Collins, Bill","Conroy, Pat","Griffin, Jim",
    "Harrison, Rose","Holland, Beth","Johnson, Jill","Kelly, Sean",
    "Michalski, Joe","Moreno, Juan","Moretti, Bella","Patel, Renee",
    "Rubin, Sarah","Sanchez, Manny","Smith, Bart","Smith, Cathy",
    "Taylor, Tyrone","Whitman, Jean","Wolfe, Bill","Wu, Hong"        };

    cout<<"Please enter the name u want to search: ";
    getline(cin,search);
    ans = binarySearch(name, SIZE, search);
    if(ans >= 0) cout<<"The position of ur request is : "<< ans <<endl;
    else cout<<"Failed to find ur request."<<endl;
    
    return 0;
}
