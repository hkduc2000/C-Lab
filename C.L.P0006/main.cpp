/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: hokiduc
 *
 * Created on March 4, 2020, 8:02 AM
 */

#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdio_ext.h>

#define clearScreen printf("\033[2J\033]H");
using namespace std;

bool doPlay(){
    printf("\nWould you like to play hangman (yes,no)?\n");
    char rep[10];
    while (true){
        __fpurge(stdin);
        scanf("%s" , rep);
        if (strlen(rep)==3){
            if (rep[0] == 'y', rep[1]=='e', rep[2] == 's') return true;
            else printf("\nPlease enter yes or no only!\n");
        } else if (strlen(rep)==2){
            if (rep[0] == 'n', rep[1]=='o') return false;
            else printf("\nPlease enter yes or no only!\n");
        } else {
            printf("\nPlease enter yes or no only!\n");
        }
    }
}

void display(char* board){
    int i = 0;
    int sw = 0;
    while (i<strlen(board)){
        (sw == 0)? printf("%c",board[i++]) : printf(" ");
        sw = 1 - sw;
    }
}

char inputGuess(bool guessed[]){
    char guess,check;
    while (true) {
        printf("\nPlease enter your guess.\n");
        __fpurge(stdin);
        scanf("%c%c", &guess, &check);
        if (guess >= 'A' && guess <= 'Z' && check=='\n') {
            if (guessed[guess-'A']){
                printf("Sorry, you guess that letter already!\n");
            } else{
                guessed[guess-'A'] = true;
                return guess;
            }
        }
        else printf("\nInvalid guess! Please enter an uppercase letter\n");
    }
}

int main(int argc, char** argv) {
    time_t t;
    srand((unsigned)time(&t));
    char inputFileName[100];
    FILE *F;
    while (true){
        printf("What file store the puzzle words?\n");
        __fpurge(stdin);
        scanf("%s", inputFileName);
        F = fopen(inputFileName,"r");
        if (F==NULL){
            printf("File not found in the directory!\n");
        } else {
            break;
        }
    }
    int noOfLines = 0;
    int maxLength = 0;
    char inp[30];
    while (fscanf(F, "%[^\n]", inp)==1){
        noOfLines++;
        if (maxLength<strlen(inp)){
            maxLength = strlen(inp);
        }
    }
    fclose(F);
    
    char words[noOfLines][maxLength];
    F = fopen(inputFileName,"r");
    int n=0;
    while (fscanf(F, "%[^\n]", words[n++])==1){}
    fclose(F);
    while (doPlay()){
        clearScreen;
        bool guessed[26];
        for (int it=0;it<26;it++) guessed[it] = false;
        int wrongGs = 0;
        int cnt = 0;
        char word[maxLength];
        strcpy(word,words[rand()%n]);
        char board[strlen(word)];
        board[strlen(word)] = '\0';
        for (int i=0;i<strlen(word);i++){
            board[i] = '_';
        }
        
        while (wrongGs<5){
            printf("\nYou currently have %d incorrect guesses.", wrongGs);
            printf("\nHere is your puzzle\n");
            display(board);
            char guess = inputGuess(guessed);
            clearScreen;
            bool existInWord = false;
            for (int i=0;i<strlen(word);i++){
                if (word[i] == guess){
                    existInWord = true;
                    board[i] = guess;
                    cnt++;
                }
            }
            if (existInWord) {
                printf("\nCongratulations, you guessed a letter in the puzzle!");
                if (cnt==strlen(word)){
                    printf("\nCongratulations! You got the correct word, %s", board);
                    break;
                }
                
            } else {
                printf("\nSorry, the letter is NOT in the puzzle.\n");
                wrongGs++;
            }
        }
        if (wrongGs==5){
            printf("\nSorry, you have made 5 incorrect guesses, you lose.");
            printf("\nThe correct word was %s", word);
        }
    }
    return 0;
}

