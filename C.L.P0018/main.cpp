/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: hokiduc
 *
 * Created on February 25, 2020, 4:20 PM
 */

#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

using namespace std;

FILE* inputFile(char* Msg, char* option){
    FILE* F;
    while (true){
        printf("\n%s", Msg);
        char fileName[100],fileDir[100];
        __fpurge(stdin);
        scanf("%s", fileName);
        strcpy(fileDir, "files/");
        strcat(fileDir,fileName);
        F = fopen(fileDir,option);
        if (F==NULL){
            printf("\nFile not found in the directory");
        } else {
            break;
        }
    } 
    return F;
}

void printFile(){
    FILE *F = inputFile("Enter the name of file you wish to see: ", "r");
    char ch;
     while((ch = fgetc(F)) != EOF)
      printf("%c", ch); 
    fclose(F);
}

void fileCopy(){
    FILE *f1,*f2;
    f1 = inputFile("Enter name of file to copy: ","r");
    f2 = inputFile("Enter name of target file: ", "w");
    char ch;
    while((ch = fgetc(f1)) != EOF) 
        fprintf(f2,"%c", ch);
    printf("File copied successfully!");
    fclose(f1);
    fclose(f2);
}

void filesMerge(){
    FILE *f1,*f2,*f3;
    f1 = inputFile("Enter name of first file: ", "r");
    f2 = inputFile("Enter name of second file: ", "r");
    f3 = inputFile("Enter name of file which will store contents of two files: ", "w");
    char ch;
    while((ch = fgetc(f1)) != EOF) 
        fprintf(f3,"%c", ch);
    
    while((ch = fgetc(f2)) != EOF) 
        fprintf(f3,"%c", ch);
    
    printf("Two files were merged into target file successfully!");
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

int main(int argc, char** argv) {
    while (true){
        char op,check;
        while (true){
            printf("\n\n1) Read files");
            printf("\n2) Copy files");
            printf("\n3) Merge two files");
            printf("\n4) List files in a directory");
            printf("\n5) Delete file");
            printf("\nChoice features: ");
            __fpurge(stdin);
            scanf("%c%c", &op, &check);
            if (op >= '1' && op <= '5' && check=='\n'){
                break;
            } else {
                printf("Invalid input!Please enter an integer from 1 to 5");
            }
        }
        
        switch (op){
            case '1':
            {
                printFile();
                break;
            }
            case '2':
            {
                fileCopy();
                break;
            }
            case '3':
            {
                filesMerge();
                break;
            }
            case '4':
            {
                DIR *dir;
                struct dirent *sd;
                dir = opendir("files/");
                while ((sd = readdir(dir)) != NULL){
                    if (sd->d_type == DT_REG)
                        printf("%s\n",sd->d_name);
                }
                closedir(dir);
                break;
            }
            case '5':
            {
                char fileName[100], fileDir[100];
                printf("Enter the name of file you wish to delete: ");
                __fpurge(stdin);
                scanf("%[^\n]s", fileName);
                strcpy(fileDir, "files/");
                strcat(fileDir,fileName);
                if (remove(fileDir)!=0){
                    perror("Error");
                } else {
                    printf("Delete successfully!");
                }
            }  
        }
    }
    return 0;
}

