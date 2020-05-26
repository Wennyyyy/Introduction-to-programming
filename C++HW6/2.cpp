#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

bool strcompare(string a, string b){
    //return true, if a < b
    for(int i=0; i< min(a.length(), b.length()); i++){
       if(a[i] < b[i]) return true; 
       else if(a[i] > b[i])return false;
    }
    return ( a.length() < b.length() );
}

void selectionSort( vector <string> &array){
	int 	start, minIndex;
    string  minValue;
	for (start = 0; start < array.size() -1; start++){
		minIndex = start;
		minValue = array[start];
		for (int index = start + 1; index < array.size(); index++){
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
    vector <string> name;
    fstream fnames;
    string temp;
    fnames.open("names.dat",ios::in);
    while(getline(fnames,temp)){
        name.push_back(temp);
    }
    fnames.close();

    selectionSort(name);
    for (int i=0; i< name.size() ; i++){
        cout<<setw(2)<<right<<i<<". "<<name[i]<<endl;
    }
    return 0;
}
