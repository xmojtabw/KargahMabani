#include <stdio.h>





char* moveToEnd(char* arr, int size) {
    int counter = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        counter++;
    }
    for (int i = 0; counter > 0; i++) {
        arr[size - i - 1] = arr[counter - 1]; arr[counter - 1] = 0;
        counter--;
    }
    return arr;
}
char* convertInt(char* number, int size) {
    for (int i = size - 1; number[i] != '\0'; i--) {
        number[i] -= 48;
    }
    return number;
}
char* SUM(char* first_num, char* second_num,char *sum,  int size) {
    ; int temp = 0; int digit_sum = 0;
    for (int i = size - 1; i >= 0; i--) {
        temp += *(first_num + i) + *(second_num + i);
        if (temp > 9) {
            *(sum +i) = temp % 10; temp = 1;
        }
        else { *(sum + i) = temp; temp = 0; }
        digit_sum++;
        
    }
    
    return sum;
}
char* MUL(char* first_number, char* second_number, char* mul, int size) {
    int temp = 0, digit = 0, nextmove = 0;
    for (int i = size - 1; i > 81; i--) {
        char sum_of_line[161] = { 0 };
        for (int j = size - 1; j > 81; j--) {
            temp += (first_number[j] * second_number[i]);
            if (temp > 9) {
                sum_of_line[j-nextmove] = temp % 10; temp /= 10;
            }
            else { sum_of_line[j - nextmove] = temp; temp = 0; }
        }
        nextmove++;
        SUM(sum_of_line, mul, mul, size);
    }
    return mul;

}
int main() {
    char first_number[161] = { 0 }, second_number[161] = { 0 }, mul[161] = { 0 };
    scanf("%s%s", first_number, second_number);
    moveToEnd(first_number, 161); moveToEnd(second_number, 161);
    convertInt(first_number, 161); convertInt(second_number, 161);
    MUL(first_number, second_number, mul, 161);
    for (int i = 0;; i++) {
        if (mul[i] != '\0') {
            for (; i <161; i++) {
                printf("%d", mul[i]);
            }
            break;
        }
    }

}