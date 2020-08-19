#include <cstdlib>
#include <stdio.h>
#include <string.h>
using namespace std;

bool checkNotInRange(char s[], char lowerB,char upperB){
    for (int i=0;i<strlen(s);i++){
        if (s[i]>=lowerB && s[i] <= upperB){
            return false;
        }
    }
    return true;
}

void deleteGarbageSpace(char *s){
    int j=0;
    char ns[1000];
    bool beingAtSpace = true;
    for (int i=0;i<strlen(s);i++){
        if (beingAtSpace){
            if (s[i] == ' '){
                continue;
            } else {
                beingAtSpace = false;
            }
        }
        ns[j++] = s[i];
        if (s[i]==' '){
            beingAtSpace = true;
        }
    }
    ns[j] = '\0';
    strcpy(s,ns);
}

int main(int argc, char** argv) {
    char key;
    do {
        char s[1000];
        while (true){
            printf("\nPlease enter a string:");
            fflush(stdin);
            fgets(s,1000,stdin);
            char special[100];
            strcpy(special, "+_)(*&^%$#@!:;'\"\\|<>`~");
            bool valid = true;
            for (int j=0;j<strlen(s);j++){
                for (int i=0;i<strlen(special);i++){
                    if (s[j] == special[i]){
                        valid = false;
                        break;
                    }
                }
            }
            if (valid) break;
            else printf("Invalid input, please don't enter special character!");
        }
        deleteGarbageSpace(s);
        printf("The string after removing: %s", s);
        printf("Press ESC to quit, enter to continue..");
        key = getchar();
        fflush(stdin);
        if (key == 27)break;
    } while (1);

    return (EXIT_SUCCESS);
}

