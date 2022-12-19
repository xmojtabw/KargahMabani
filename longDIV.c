#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)

int deff;

char* SMALL_MUL(char* first_number, int second_num, char* mul, int size) {
    int temp = 0;
    for (int i = size - 1; i >= 0; i--) {
        temp += (first_number[i] * second_num);
        if (temp > 9) {
            mul[i] = temp % 10; temp /= 10;
        }
        else { mul[i] = temp; temp = 0; }
    }
    return mul;
}
int digitcounter(char* arr) {
    int counter = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        counter++;
    }
    return counter;
}

char* convertInt(char* number) {
    for (int i = 0; number[i] != '\0'; i++) {
        number[i] -= 48;
    }
    return number;
}
char* movenext(char* arr, int size, int step) {
    for (int i = size - 1; i - step > -1; i--) {
        arr[i] = arr[i - step]; arr[i - step] = 0;
    }
    return arr;
}
int compare(char* first_num, char* second_num, int size) {
    for (int i = 0; i < size; i++) {
        if (first_num[i] > second_num[i])return 1;
        else if (first_num[i] < second_num[i])return 0;
    }
    return 2;
}
char* SUB(char* first_num, char* second_num, char* sub, int size) {
    ; int temp = 0;
    for (int i = size - 1; i >= 0; i--) {
        temp += *(first_num + i) - *(second_num + i);
        if (temp < 0) {
            *(sub + i) = 10 + temp; temp = -1;
        }
        else { *(sub + i) = temp; temp = 0; }
    }
    return sub;
}
char* copy(char* first, char* second, int size) {
    for (int i = 0; i < size - 1; i++) {
        second[i] = first[i];
    }
    return second;
}
char* DIV(char* first_num, char* second_num, char* div, int size) {
    char temp_second_num[300] = { 0 }; copy(second_num, temp_second_num, size);

    for (int i = 0; i < size - 1; i++) {
        int temp1 = 0;
        char guess[300] = { 0 };
        for (int j = 0; j < 10; j++) {
            SMALL_MUL(second_num, j, guess, size);
            if ((compare(first_num, guess, size))) {//firstnum>guess
                temp1 = j;
            }
        }
        div[i] = temp1;

        SMALL_MUL(second_num, temp1, guess, size);
        SUB(first_num, guess, first_num, size);
        movenext(second_num, size, 1);
    }
    return div;
}

int main() {
    char first_number[300] = { 0 }, div[300] = { 0 }, second_number[300] = { 0 }; int first_num_digits = 0, second_num_digit = 0;
    int compare_check = 0;
    scanf("%s%s", first_number, second_number);
    first_num_digits = digitcounter(first_number); second_num_digit = digitcounter(second_number);
    deff = first_num_digits - second_num_digit;
    compare_check = compare(first_number, second_number, 300);
    convertInt(first_number); convertInt(second_number); if (second_number[0] == 0 && first_number[0] == 0) { printf("NaN"); return 0; }
    if (second_number[0] == 0) { printf("Can't divide by zero"); return 0; }
    if (first_number[0] == 0) { printf("0"); return 0; }
    movenext(first_number, 300, 1); movenext(second_number, 300, 1);
    DIV(first_number, second_number, div, 300);
    if ((deff < 0) || (compare_check == 0 && deff == 0)) {
        printf("0"); div[299] = -2;
    }
    for (int i = 298; div[i] == 0 && i >= ((deff)+1); i--) {
        div[i] = -1;
    }

    if (compare_check) {
        int i = 0;
        for (; i < deff + 1; i++) {

            printf("%d", div[i]);
        }
        if (div[i] > -1) {
            printf(".");
            if (div[299] == -2) {
                for (int j = 0; j < abs(deff)-1; j++) {
                    printf("0");
                }
            }
            for (; div[i] > -1; i++) {
                printf("%d", div[i]);
            }
        }

    }
    else {
        int i = 1;
        for (; i < deff + 1; i++) {

            printf("%d", div[i]);
        }
        if (div[i] > -1) {
            printf(".");
            if (div[299] == -2) {
                for (int j = 0; j < abs(deff) ; j++) {
                    printf("0");
                }
            }
            for (; div[i] > -1; i++) {
                printf("%d", div[i]);
            }
        }
    }
}