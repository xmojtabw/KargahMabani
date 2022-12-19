#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
int lowercheck(char* sus_w, char* true_w) {
    int counter = 0; char sw[51] = { 0 }, tw[51] = { 0 };
    int x = strlen(true_w); int y = strlen(sus_w);
    if (x != y)return 0;
    for (int i = 0; i < x; i++) {
        sw[i] = tolower(sus_w[i]); tw[i] = tolower(true_w[i]);
        if (sw[i] != tw[i])counter++;
        if (counter > 0)return 0;
    }

    return 1;
}
int changeone(char* sus_w, char* true_w) {
    int counter = 0;
    int x = strlen(true_w); int y = strlen(sus_w);
    if (x != y)return 0;
    for (int i = 0; i < x; i++) {
        if (sus_w[i] != true_w[i]) {
            counter++;
            if (counter > 1)return 0;
        }

    }
    return 1;
}
int deleteone(char* tw, char* sw) {
    int x = strlen(tw); int y = strlen(sw);
    if (abs(x - y) != 1)return 0;
    if (x > y) {
        for (int i = 0; i < y; i++) {
            if (sw[i] != tw[i]) {
                for (; i < y; i++) {
                    if (sw[i] != tw[i + 1])return 0;
                }
                return 1;
            }
        }
    }
    else {
        for (int i = 0; i < x; i++) {
            if (sw[i] != tw[i]) {
                for (; i < x; i++) {
                    if (sw[i + 1] != tw[i])return 0;
                }
                return 1;
            }
        }
    }
}
int main() {
    int number_n_s = 0, number_k_t = 0; scanf("%d%d", &number_n_s, &number_k_t);
    /**************************************************************/
    char** suswords = (char**)calloc(number_n_s, sizeof(char*));
    for (int i = 0; i < number_n_s; i++) {
        suswords[i] = (char*)calloc(51, sizeof(char));
        scanf("%s", suswords[i]);
    }
    char** truewords = (char**)calloc(number_k_t, sizeof(char*));
    for (int i = 0; i < number_k_t; i++) {
        truewords[i] = (char*)calloc(51, sizeof(char));
        scanf("%s", truewords[i]);
    }
    int* similar = (int*)calloc(number_k_t, sizeof(int));
    for (int i = 0; i < number_n_s; i++) {
        int x = 0;
        for (int j = 0; j < number_k_t; j++) {
            x = (lowercheck(suswords[i], truewords[j]) + deleteone(truewords[j], suswords[i]) + changeone(suswords[i], truewords[j]));
            if (x > 0)similar[j]++;
        }
        
    }
    for (int i = 0; i < number_k_t; i++) {
        printf("%d\n", similar[i]);
    }
}