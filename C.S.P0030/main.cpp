/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: hokiduc
 *
 * Created on March 4, 2020, 8:01 AM
 */

#include <cstdlib>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

using namespace std;

int checkInputInt(char* msg){
    int n;
    char c;
    while (true){
        printf("%s", msg);
        __fpurge(stdin);
        int check = scanf("%d%c", &n,&c);
        if (check==2 && c=='\n'){
            if (n>=0){
                return n;
            } else {
                printf("\nInvalid input! Please enter an non-negative integer.");
            }
        } else {
            printf("\nInvalid input! Please enter an integer.");
        }
    }
}

int main(int argc, char** argv) {
    printf("Sum Even Odd program");
    int n = checkInputInt("\nEnter the number of elements n=");
    int a[n];
    printf("Input Elements:\n");
    for (int i=0;i<n;i++){
        char istr[10];
        sprintf(istr, "%d", i+1);
        char msg[30];
        strcpy(msg,"\tElement ");
        strcat(msg, istr);
        strcat(msg, "=");
        a[i] = checkInputInt(msg);
    }
    int sumOdd = 0, sumEven =0;
    for (int i=0;i<n;i++){
        (a[i]%2==0)? sumEven+=a[i] : sumOdd+=a[i];
    }
    printf("\nSum of Even=%d", sumEven);
    printf("\nSum of Odd=%d", sumOdd);
    return 0;
}

