// 1) Money Donation (10%)
// Modify Program Example in pptx pp.10-108 (the United Cause case study program)
//so it can be used with any set of donations.
//The program should dynamically allocate the donations array and ask the user to input its values.
//Then modify the program so the arrPtr array is sorted in descending order instead of ascending order.
#include <iostream>
using namespace std;
class DonationList{
    private:
        int 	numDonations;
        double 	*donations;
        double 	**arrPtr; //array of pointer
        void 	selectSort();
    public:
        DonationList(int num, double gifts[]);
        ~DonationList();
        void show();
        void showSorted();
};
DonationList::DonationList(int num, double gifts[]){
	numDonations = num;
	if (num > 0){
		// Allocate an array of doubles
		donations = new double[num];
		// Allocate an array of pointers-to-doubles.
		this->arrPtr = new double*[num];
		// Initialize the arrays
		for (int count = 0; count < numDonations; count++)
		{
			donations[count] = gifts[count];
			this->arrPtr[count] = &donations[count];
		}
		// Now sort the array of pointers
		selectSort();
	}
}
void DonationList::selectSort(){
	int maxIndex;
	double *maxElem;
	for (int scan = 0; scan < (numDonations - 1); scan++)
	{
		maxIndex = scan;
		maxElem = arrPtr[scan];
		for(int i = scan + 1; i < numDonations; i++)
		{
			if (*(arrPtr[i]) > *maxElem)
			{
				maxElem = arrPtr[i];
				maxIndex = i;
			}
		}
		arrPtr[maxIndex] = arrPtr[scan];
		arrPtr[scan] = maxElem;
	}
}
void DonationList::show(){
	for (int count = 0; count < numDonations; count++)
		cout << donations[count] << " ";
	cout << endl;
}
void DonationList::showSorted(){
	for (int count = 0; count < numDonations; count++)
		cout << *(arrPtr[count]) << " ";
	cout << endl;
}
DonationList::~DonationList(){
    if (numDonations > 0){
        delete [ ] donations;
        donations = 0;
        delete [ ] arrPtr;
        arrPtr = 0;
    }  
}
int main(int argc, char * argv[]){
    double given[100];
    int i=0,len=0;
    cout <<"enter donations: (0 means stop) ";
    cin >> given[i];
    while(given[i] != 0){
            i++; cin >> given[i];
        }
    len = i;
    DonationList donationlist(len,given);
    donationlist.show();
    donationlist.showSorted();
    return 0;
}

