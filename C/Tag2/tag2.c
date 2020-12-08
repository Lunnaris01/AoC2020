//
// Created by julian on 08.12.20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int checkvalid_1(char *line) {
    char *min;
    char *max;
    char *letter;
    char *password;
    const char s[2] = "-";
    min = strtok(line, s);
    max = strtok(NULL," ");
    letter = strtok(NULL,": ");
    password = strtok(NULL," ");
    //
    int lettercounter = 0;
    for(int i=0;i<strlen(password);i++){
        if(letter[0] == password[i]){
            lettercounter++;
        }
    }
    if(lettercounter>=atoi(min) && lettercounter<=atoi(max)){
        return 1;
    }
    return 0;

}

int checkvalid_2(char *line) {
    char *first;
    char *second;
    char *letter;
    char *password;
    const char s[2] = "-";
    first = strtok(line, s);
    second = strtok(NULL," ");
    letter = strtok(NULL,": ");
    password = strtok(NULL," ");
    //
    int result = (letter[0] == password[atoi(first)-1]) + (letter[0] == password[atoi(second)-1]);
    if(result == 1){
        return 1;
    }
    return 0;

}


int main() {
    FILE *input = fopen("../../res/input_2.txt", "r");

    char line[99];
    int correctpasswords = 0;
    int correctpasswords_2 = 0;
    while (fgets(line, 99, input) != NULL) {
        correctpasswords = correctpasswords + checkvalid_1(line);
    }

    printf("Teil 1: %d\n", correctpasswords);

    rewind(input);

    while (fgets(line, 99, input) != NULL) {
        correctpasswords_2 = correctpasswords_2 + checkvalid_2(line);
    }
    printf("Teil 2: %d\n", correctpasswords_2);

}