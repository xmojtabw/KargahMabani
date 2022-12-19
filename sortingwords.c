#include <stdio.h>
#include <ctype.h>
#include <string.h>
int firstcompare(char first_word1, char first_word2) { //a>B.. first>second= 1...second>first=0...first=second=2..
    char litter1 = first_word1; char litter2 = first_word2;
    first_word1 = tolower(first_word1); 
    first_word2 = tolower(first_word2); 
    if (first_word1 > first_word2) {
        return 1;
    }
    else if (first_word1 < first_word2) {
        return 0;
    }
    else {
        if (litter1 > litter2) {
            return 1;
        }
        else if (litter1 < litter2) {
            return 0;
        }
        else return 2;
    }
}

int numbericcompare(char first_word1, char first_word2) {
    if (first_word1 > first_word2) {
        return 1;
    }
    else if (first_word1 < first_word2) {
        return 0;
    }
    else return 2;
}
void copy(char* tothis, char* thiis) {
    for (int i = 0; thiis[i] != 0 || thiis[i + 1] != 0||thiis[i+2]!=0; i++) {
        tothis[i] = thiis[i];
    }
}
int main(void) {
    char words[1000][1006] = { 0 }; int counter = 0;
    for (int i = 0;; i++) {
        scanf("%s", &words[i]);
        if (words[i][0] == '0') {
            break;
        }
        int l = strlen(words[i]);
        counter++;
        words[i][l + 2] = counter % 100;
        words[i][l + 1] = counter / 100;
    }
    for (int i = 0; i < counter-1; i++) {
        char lowest[1000] = { 0 }; copy(lowest, words[i]); int temp = i;
        for (int j = i + 1; j < counter; j++) {
            
            int a = firstcompare(lowest[0], words[j][0]) ;
            if (a==1) {
                copy(lowest, words[j]); temp = j;
            }
            if (a == 2) {
                if (words[j][1] == 0) {
                    copy(lowest, words[j]); temp = j;
                }
                else {
                    a = firstcompare(lowest[1], words[j][1]);
                    if (a == 1) {
                        copy(lowest, words[j]); temp = j;
                    }
                    if (a == 2) {
                        int l1 = strlen(lowest); int l2 = strlen(words[j]);
                        a = numbericcompare(lowest[l1 + 1], words[j][l2 + 1]);
                        if(a==2)a= numbericcompare(lowest[l1 + 2], words[j][l2 + 2]);
                        if (a == 1) {
                            copy(lowest, words[j]); temp = j;
                        }
                    }
                }
            }
            
        }
        copy(words[temp], words[i]);
        copy(words[i], lowest); 
    }
    for (int i = 0; i < counter; i++) {
        printf("%s ", words[i]);
    }
}