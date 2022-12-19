#include <stdio.h>
char * convertInt(char * number) {
    for (int i = 80; number[i] != '\0'; i--) {
        number[i] -= 48;
    }
    return number;
}
char * moveToEnd(char* arr, int size) {
    int counter = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        counter++;
    }
    for (int i = 0; counter > 0; i++) {
        arr[size - i-1] = arr[counter - 1]; arr[counter - 1] = 0;
        counter--;
    }
    return arr;
}
char* SUM(char* first_num, char* second_num,char *sum) {
    ; int temp=0; int digit_sum = 0;
    for (int i = 80; i >=0; i--) {
        temp += *(first_num + i) + *(second_num + i);
        if (temp > 9) {
            *(sum + digit_sum) = temp % 10; temp = 1;
        }
        else{ *(sum + digit_sum)  = temp; temp = 0; }
        digit_sum++;
    }  
    return sum;
}
int main() {
    char first_numbers[81] = { 0 }; char second_number[81] = { 0 }; char sum[81] = { 0 };
    scanf("%s%s", first_numbers, second_number);
    moveToEnd(first_numbers, 81); moveToEnd(second_number, 81);   
    convertInt(first_numbers); convertInt(second_number);   
    SUM(first_numbers, second_number,sum);
    for (int i = 80;; i--) {
        if (sum[i] != '\0') {
            for (; i >= 0; i--) {
                printf("%d", sum[i]);
            }
            break;
        }
    }


}