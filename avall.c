#include <stdio.h>
#pragma warning(disable:4996)
int digit(int n) {
    if (n % 10 == 2 || n % 10 == 3 || n % 10 == 5 || n % 10 == 7) {
        n -= (n % 10); n /= 10;
        if (n > 0) {
            if (digit(n)) {
                return 1;
            }
            else return 0;
        }
        else return 1;
    }
    else return 0;
}
int main() {
    int aval[3500] = { 0 }; int x = 0, temp = 0;
    for (int i = 0, j = 2; i < 30000; i++) {
        for (j = 2; j <= (i / 2); j++) {
            if (i % j == 0)break;
        }
        if (i / 2 < j && i > 1) {
            aval[x] = i; x++;
        }
    }
    temp = 0;
    //now check if all digits are aval
    int zyadAval[300] = { 0 };
    for (int i = 0, j = 0; i < 3240; i++) {
        temp = aval[i];
        if (digit(temp)) {
            zyadAval[j] = aval[i]; j++;
        }
    }
    int num = 0, i = 0;
    scanf("%d", &num);
    while (num > zyadAval[i] && i < 89) {

        printf("%d ", zyadAval[i]); i++;


    }
    
}


