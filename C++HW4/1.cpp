#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class Employee
{
    private:
        string name;
        int idNumber;
        string department;
        string position;
    public:
        Employee(string empN,int empID,string empD,string empP);
		Employee(string empN,int empID);
		Employee();
        void setName(string );
        void setID(int );
        void setDepartment(string );
        void setPosition(string );
        string getName();
        int getID();
        string getDepartment();
        string getPosition();
};
Employee::Employee(string empN,int empID,string empD,string empP)
{
    name=empN;
    idNumber=empID;
    department=empD;
    position=empP;
}
Employee::Employee(string empN,int empID)
{
    name=empN;
    idNumber= empID;
    department="";
    position="";
}
Employee::Employee()
{
    name=" ";
    idNumber=0;
    department=" ";
    position=" ";
}
void Employee::setName(string empN)
{
    name = empN;
}
void Employee::setID(int empID)
{
    idNumber = empID;
}
void Employee::setDepartment(string empD)
{
    department = empD;
}
void Employee::setPosition(string empP)
{
    position = empP;
}
string Employee::getName()
{
    return name;
}
int Employee::getID()
{
    return idNumber;
}
string Employee::getDepartment()
{
    return department;
}
string Employee::getPosition()
{
    return position;
}
int main()
{
    Employee emp1 ("Susan Meyers" , 47899 , "Accounting" , "Vice President");
    Employee emp2 ("Mark Jones" , 39119,     "IT", "Programmer");
    Employee emp3 ("Chris Raines" , 81774, "Manufacturing" , "Engineer");

    cout<<setw(20)<<left<<"Name"<<setw(20)<<left<<"ID number"<<setw(20)
        <<left<<"Department"<<setw(20)<<left<<"Position"<<endl;

    cout<<setw(20)<<left<<emp1.getName()<<setw(20)<<left<<emp1.getID()<<setw(20)<<left<<emp1.getDepartment()
        <<setw(20)<<left<<emp1.getPosition()<<endl;
    cout<<setw(20)<<left<<emp2.getName()<<setw(20)<<left<<emp2.getID()<<setw(20)<<left<<emp2.getDepartment()
        <<setw(20)<<left<<emp2.getPosition()<<endl;
    cout<<setw(20)<<left<<emp3.getName()<<setw(20)<<left<<emp3.getID()<<setw(20)<<left<<emp3.getDepartment()
        <<setw(20)<<left<<emp3.getPosition()<<endl;
    return 0;
}
