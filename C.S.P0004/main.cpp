/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: hokiduc
 *
 * Created on February 18, 2020, 11:09 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <string.h>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char s[1000], key;
    int const size = 129;
    int cnt[size];
    do {
        for (int i=0;i<size;i++){
            cnt[i] = 0;
        }
        printf("Please enter string: ");
        fgets(s,1000,stdin);
        for (int i=0; i<strlen(s);i++){
            cnt[s[i]]++;
        }
        printf("Times of appearance for each character: \n");
        for (int i=0;i<size;i++){
            if (cnt[i] > 0){
                printf("  %c", i);
            }
        }
        printf("\n");
        int mostApp = 0;
        for (int i=0;i<size;i++){
            if (cnt[i] > 0){
                printf("  %d", cnt[i]);
                if (mostApp < cnt[i]) mostApp = cnt[i];
            }
        }
        printf("\n-----------------------------------------------------");
        printf("\nCharacters that appears the most:\n");
        for (int i=0;i<size;i++){
            if (cnt[i] == mostApp){
                printf("  %c", i);
            }
        }
        printf("\n");
        for (int i=33;i<size;i++){
            if (cnt[i] == mostApp){
                printf("  %d", cnt[i]);
            }
        }
        printf("\n");
        printf("Press ESC to quit, enter to continue..");
        key = getchar();
        fflush(stdin);
        if (key == 27)break;
    } while (1);

    return (EXIT_SUCCESS);
}

