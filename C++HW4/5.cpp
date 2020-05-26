#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class PatientAccount{
    public:
        int charges;
        int numberOfDay;
        int rate;
        PatientAccount(){
            charges = 0;
            numberOfDay = 0;
            rate = 100;
        }

};

class Surgery{
    public:
        string surgery1;
        string surgery2;
        string surgery3;
        string surgery4;
        string surgery5;
        int surgery1_charges;
        int surgery2_charges;
        int surgery3_charges;
        int surgery4_charges;
        int surgery5_charges;
        Surgery(){
            surgery1 = "surgery1";
            surgery2 = "surgery2";
            surgery3 = "surgery3";
            surgery4 = "surgery4";
            surgery5 = "surgery5";

            surgery1_charges = 100;
            surgery2_charges = 200;
            surgery3_charges = 300;
            surgery4_charges = 400;
            surgery5_charges = 500;
        }
        bool updateCharges(PatientAccount &patientAccount, int type){
            switch(type){
                case 1: patientAccount.charges += surgery1_charges;break;
                case 2: patientAccount.charges += surgery2_charges;break;
                case 3: patientAccount.charges += surgery3_charges;break;
                case 4: patientAccount.charges += surgery4_charges;break;
                case 5: patientAccount.charges += surgery5_charges;break;
                default: return false;break;
            }

            return true;
        }

};

class Pharmacy{
    public:
        string medication1;
        string medication2;
        string medication3;
        string medication4;
        string medication5;
        int medication1_charges;
        int medication2_charges;
        int medication3_charges;
        int medication4_charges;
        int medication5_charges;
        Pharmacy(){
            medication1 = "medication1";
            medication2 = "medication2";
            medication3 = "medication3";
            medication4 = "medication4";
            medication5 = "medication5";

            medication1_charges = 100;
            medication2_charges = 200;
            medication3_charges = 300;
            medication4_charges = 400;
            medication5_charges = 500;
        }
        bool updateCharges(PatientAccount &patientAccount, int type){
            switch(type){
                case 1: patientAccount.charges += medication1_charges;break;
                case 2: patientAccount.charges += medication2_charges;break;
                case 3: patientAccount.charges += medication3_charges;break;
                case 4: patientAccount.charges += medication4_charges;break;
                case 5: patientAccount.charges += medication5_charges;break;
                default: return false; break;
            }

            return true;
        }

};

int main(){
    PatientAccount patientAccount;
    Surgery surgery;
    Pharmacy pharmacy;
    int surgeryType;
    int medicationType;

    bool chooseSurgeryFin = false;
    bool choosePharmacyFin = false;
    char  pharmacy_continue;
    while(!chooseSurgeryFin){
        cout<<"________________________________________"<<endl;
        cout<<"Which type of the sugery did u have? "<<endl;
        cout<<"1. "<<surgery.surgery1<<"  charges:"<<surgery.surgery1_charges<<endl
            <<"2. "<<surgery.surgery2<<"  charges:"<<surgery.surgery2_charges<<endl
            <<"3. "<<surgery.surgery3<<"  charges:"<<surgery.surgery3_charges<<endl
            <<"4. "<<surgery.surgery4<<"  charges:"<<surgery.surgery4_charges<<endl
            <<"5. "<<surgery.surgery5<<"  charges:"<<surgery.surgery5_charges<<endl;
        cin>>surgeryType;
        if((chooseSurgeryFin = surgery.updateCharges(patientAccount,surgeryType)) == false )
            cout<<"Should input 1~5"<<endl;
    }

    while(!choosePharmacyFin){
        cout<<"________________________________________"<<endl;
        cout<<"Which type of the medication did u have? "<<endl;
        cout<<"1. "<<pharmacy.medication1<<"  charges:"<<pharmacy.medication1_charges<<endl
            <<"2. "<<pharmacy.medication2<<"  charges:"<<pharmacy.medication2_charges<<endl
            <<"3. "<<pharmacy.medication3<<"  charges:"<<pharmacy.medication3_charges<<endl
            <<"4. "<<pharmacy.medication4<<"  charges:"<<pharmacy.medication4_charges<<endl
            <<"5. "<<pharmacy.medication5<<"  charges:"<<pharmacy.medication5_charges<<endl;
        cin>>medicationType;
        if((choosePharmacyFin = pharmacy.updateCharges(patientAccount,medicationType)) == false )
            cout<<"Should input 1~5"<<endl;
        else{
            cout<<"Do u need to input  other treatment? (Y/N) ";
            cin>>pharmacy_continue;
            if (pharmacy_continue=='Y'||pharmacy_continue=='y') choosePharmacyFin=0;
            else choosePharmacyFin=1;
        }

    }
    cout<<"________________________________________"<<endl;
    cout<<"The rate of the hospital is : "<<patientAccount.rate<<endl;
    cout<<"Please enter ur day spent in the hospital : ";
    cin>>patientAccount.numberOfDay;
    cout<<"________________________________________"<<endl;
    patientAccount.charges += patientAccount.numberOfDay * patientAccount.rate;
    cout<<"You should pay: "<<patientAccount.charges<<endl;

    return 0;
}
