#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *input = fopen("../../res/input_1.txt", "r");

    char line[99];
    int linecounter = 0;

    while (fgets(line, 99, input) != NULL) {
        linecounter++;
    }
    int numbers[linecounter];
    rewind(input);
    int i = 0;
    while (fgets(line, 99, input) != NULL) {
        sscanf(line, "%d", &numbers[i]);
        i++;
    }
    for (int i = 0; i < linecounter; i++) {
        for (int j = i; j < linecounter; j++) {
            if ((numbers[i] + numbers[j]) == 2020) {
                printf("Ergebnis: %d\n", numbers[i] * numbers[j]);
            }
        }
    }
    for (int i = 0; i < linecounter; i++) {
        for (int j = i; j < linecounter; j++) {
            for (int k = j; k < linecounter; k++) {
                if ((numbers[i] + numbers[j] + numbers[k]) == 2020) {
                    printf("Ergebnis 2: %d\n", numbers[i] * numbers[j]*numbers[k]);
                }
            }
        }
    }


    return 0;
}
