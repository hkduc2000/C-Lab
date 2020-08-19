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
    int n = checkInputInt("\nEnter the number of elements: ");
    int a[n];
    for (int i=0;i<n;i++){
        char msg[30];
        sprintf(msg, "Element[%d] = ", i+1);
        a[i] = checkInputInt(msg);
    }
    printf("\nThe original array:\n");
    for (int i=0;i<n;i++){
        printf("%d\t", a[i]);
    }
    int na[n];
    int cnt = 0;
    for (int i=0;i<n;i++){
        bool unique = true;
        for (int j=0;j<cnt;j++){
            if (na[j]==a[i]) {
                unique = false;
                break;
            }
        }
        if (unique){
            na[cnt++] = a[i];
        }
    }
    printf("\nThe array after removing duplicate elements:\n");
    for (int i=0;i<cnt;i++){
        printf("%d\t", na[i]);
    } 
    return 0;
}

