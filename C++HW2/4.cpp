#include<iostream>
#include<iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
int choice;
int ans;
bool game=1;
int main (){
    do{
        const int min=10,max=50;
        srand( time(NULL) );
        int q1 = rand() % (max - min + 1) + min;
        int q2 = rand() % (max - min + 1) + min;
        cout<<"MENU"<<endl<<"Choose whichever u want to practice: "<<endl
        <<"1. addition"<<endl
        <<"2. subtraction"<<endl
        <<"3. multiplication"<<endl
        <<"Or choose 4 to exit"<<endl;
        cin>>choice;
        if(choice<=0&&choice>4) cout<<"Error!"<<endl;
        switch(choice){
                    case 1:
                        cout<<"Start practice of adding two numbers:"<<endl;
                            cout<<" "<<q1<<endl;
                            cout<<"+"<<q2<<endl;
                            cout<<"____"<<endl<<" ";
                            cin>>ans;
                            if(ans==q1+q2) cout<<"~~~congratulations~~~"<<endl;
                            else cout<<"!!! the correct answer is "<<q1+q2<<"!!!"<<endl;
                        break;
                    case 2:
                        cout<<"Start practice of subtracting two numbers:"<<endl;
                            cout<<" "<<q1<<endl;
                            cout<<"-"<<q2<<endl;
                            cout<<"____"<<endl<<" ";
                            cin>>ans;
                            if(ans==q1-q2) cout<<"~~~congratulations~~~"<<endl;
                            else cout<<"!!! the correct answer is "<<q1-q2<<"!!!"<<endl;
                        break;
                    case 3:
                        cout<<"Start practice of multiplying two numbers:"<<endl;
                            cout<<" "<<q1<<endl;
                            cout<<"*"<<q2<<endl;
                            cout<<"____"<<endl<<" ";
                            cin>>ans;
                            if(ans==q1*q2) cout<<"~~~congratulations~~~"<<endl;
                            else cout<<"!!! the correct answer is "<<q1*q2<<"!!!"<<endl;
                        break;
                    case 4:
                        game=0;
                        break;
            }
    }while((choice<=0&&choice>4)||game);

    return 0;
}
