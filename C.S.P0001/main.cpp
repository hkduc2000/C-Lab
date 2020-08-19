/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: hokiduc
 *
 * Created on February 18, 2020, 10:09 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <stdio_ext.h>

using namespace std;


int main(int argc, char** argv) {
    char key;
    do {
        char s[1000], ns[1000];
        strcpy(ns,"");
        printf("\nPlease enter string: ");
        fflush(stdin);
        scanf("%[^\n]s", s);
        printf("The old string: %s", s);
        int l = strlen(s)-1 ,r = strlen(s);
        while (l>=0){
            if (s[l-1]=='_' || l==0){
                char subs[r-l];
                memcpy(subs, &s[l], r-l);
                subs[r - l] = '\0';
                strcat(ns, subs);
                strcat(ns, "_");
                r = l-1;
                l--;
            }
            l--;
        }
        ns[strlen(s)] = '\0';
        printf("\nThe reversed string: %s", ns);
        
        printf("\nPress ESC to quit, enter to continue..");
        __fpurge(stdin);
        key = getchar();
        __fpurge(stdin);
        if (key == 27)break;
    } while (1);
    return (EXIT_SUCCESS);
}

