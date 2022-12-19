#include <stdio.h>
int strlen(char* str) {
    int i = 0;
    for (; str[i] != '\0'; i++);
    return i;
}
int main() {
    char sentence[100010] = { 0 };
    scanf("%s", sentence);
    int x = strlen(sentence); int cntr = 0;
    char sen[100000] = { 0 };
    for (int i = x, j = 0; i >= 0; i--) {
        if (sentence[i] == 61) {
            cntr--;
        }
        else {
            if (cntr > 0) {
                sen[j] = sentence[i]; j++;
            }
            else cntr++;
        }
    }
    x = strlen(sen);
    int j = 0;
    for (int i = x; i > 0; i--) {
        sentence[j] = sen[i-1]; j++;
    }
    sentence[j] = '\0';
    printf("%s", sentence);
}