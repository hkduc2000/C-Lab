/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: hokiduc
 *
 * Created on February 18, 2020, 10:12 PM
 */

#include <cstdlib>
#include <stdio.h>
using namespace std;

void swap(int *a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int checkInputInt(char* msg){
    int num, check;
    char ch;
    while (true){
        printf("%s", msg);
        check = scanf("%d%c", &num, &ch);
        if (check==2 && ch=='\n'){
            break;
        } else {
            printf("Invalid input, please enter an Integer");
        }
    }
    return num;
}

int main(int argc, char** argv) {
    int n = checkInputInt("Please enter size of array: ");
    int *arr;
    arr = (int*) malloc(n*sizeof(int));
    for (int i=0;i<n;i++){
        printf("Enter element[%d]: ",i);
        arr[i] = checkInputInt("");
    }
    // sort
    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            if (arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("The array after sorting:\n");
    for (int i=0;i<n;i++){
        printf(" %d", arr[i]);
    }
    //new element
    n++;
    arr = (int*) realloc(arr,n*sizeof(int));
    arr[n-1] = checkInputInt("\nPlease enter new value: ");
    int i = n-1;
    while (i>0 && arr[i]<arr[i-1]){
        int temp = arr[i];
        arr[i] = arr[i-1];
        arr[i-1] = temp;
        i--;
    }
    printf("New array:\n");
    for (int i=0;i<n;i++){
        printf(" %d", arr[i]);
    }
    return 0;
}

