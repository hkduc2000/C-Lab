/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: hokiduc
 *
 * Created on February 21, 2020, 8:20 AM
 */

#include <cstdlib>
#include <time.h>
#include <stdio.h>

using namespace std;

void saveBalance(float balance){
    FILE *F;
    F = fopen("balance.txt", "w");
    fprintf(F,"%lf", balance);
    fclose(F);
    printf("\nYour money is saved");
}

void playTheSlotMachine(float* balance){
    *balance -= 0.25;
    time_t t;
    srand((unsigned)time(&t));
    int num1 = rand() % 10;
    int num2 = rand() % 10;
    int num3 = rand() % 10;
    printf("\nThe slot machine shows %d%d%d.", num1,num2,num3);
    if (num1==num2 && num2==num3){
        *balance += 10;
        printf("\nYou win the big price, 10.00$!");
    } else if (num1 == num2 || num2 == num3 || num1 == num2){
        *balance += 0.5;
        printf("\nYou win 50 cents!");
    } else {
        printf("\nSorry you don't win anything.");
    }
    printf("\nYou have %.2lf", *balance);    
    if (*balance == 0){
        saveBalance(*balance);
        printf("\nThank you for playing! You end with 0.00$");
        exit(0);
    }
}

int main(int argc, char** argv) {
    float balance=0;
    FILE *F;
    F = fopen("balance.txt", "r");
    if (F==NULL){
        balance = 10;
    } else {
        fscanf(F, "%f", &balance);
        fclose(F);
    }

    if (balance == 0){
        balance = 10;
    }
    printf("\nYou have %.2lf", balance);
    while (true){
        char op, check;
        while (true){
            printf("\nChoose one of the following menu options :");
            printf("\n1) Play the slot machine.");
            printf("\n2) Save game.");
            printf("\n3) Cash out.");
            printf("\nEnter: ");
            fflush(stdin);
            scanf("%c%c", &op, &check);
            if (op >= '1' && op <= '3' && check == '\n'){
                break;
            } else {
                printf("Invalid input!Please enter an integer from 1 to 3");
            }
        }
        switch (op){
            case '1':
            {
                playTheSlotMachine(&balance);
                break;
            }
            case '2':
            {
                saveBalance(balance);
                break;
            }
            case '3':
            {
                printf("Thank you for playing! You end with %.2f", balance);
                saveBalance(balance);
                exit(0);
            }               
        }
    }
    return 0;
}

