#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<windows.h>
#include<string>
#include<time.h>
using namespace std;

int main(int argc, char* argv[]){
    string worm[6][3];
    worm[0][0] = "        \\/          ";
    worm[0][1] = "        00          ";
    worm[0][2] = "-000000000          ";
    worm[1][0] = "        \\/          ";
    worm[1][1] = "      0 00          ";
    worm[1][2] = "-00000 000          ";
    worm[2][0] = "        \\/          ";
    worm[2][1] = "     00 00          ";
    worm[2][2] = " -000  000          ";
    worm[3][0] = "        \\/          ";
    worm[3][1] = "    000 00          ";
    worm[3][2] = "  -0   000          ";
    worm[4][0] = "        \\/          ";
    worm[4][1] = "   00   00          ";
    worm[4][2] = " -0  00000          ";
    worm[5][0] = "        \\/          ";
    worm[5][1] = "  0     00          ";
    worm[5][2] = "-0 0000000          ";
    int start_ptr = 0;
    int milliseconds = 500;
    printf("  Moving inchworm  \n");
    while(true){
        for(int i = 0; i < 4; i++){
            printf("----------------------\n");
            for(int j = 0; j<3; ++j){
                printf("|");
                for(int k = 0; k<20; ++k){
                    printf("%c",worm[i][j][(k + start_ptr)%20]);
                }
                printf("|\n");
            }
            printf("----------------------\n");
            Sleep(milliseconds);
            system("cls");
        }

        for(int i = 4; i <6; i++){
            start_ptr--;
            if(start_ptr<0) start_ptr = 19;
            printf("----------------------\n");
            for(int j = 0; j<3; ++j){
                printf("|");
                for(int k = 0; k<20; ++k){
                    printf("%c",worm[i][j][(k + start_ptr)%20]);
                }
                printf("|\n");
            }
            printf("----------------------\n");
            Sleep(milliseconds);
            system("cls");
        }

    }
}
