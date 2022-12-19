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
int compare(char *first_num,char*second_num,int size){
    for(int i=0;i<size;i++){
        if(first_num[i]>second_num[i])return 1;
        else if(first_num[i]<second_num[i])return 0;
    }
    return 2;
}
char* SUB(char* first_num, char* second_num,char *sub) {
    ; int temp=0; int digit_sub = 0;
    for (int i = 80; i >=0; i--) {
        temp += *(first_num + i) - *(second_num + i);
        if (temp < 0) {
            *(sub + digit_sub) = 10+temp; temp = -1;
        }
        else{ *(sub + digit_sub)  = temp; temp = 0; }
        digit_sub++;
    }  
    return sub;
}
int main(){
    char first_num[81]={0},second_num[81]={0},sub[81]={0};
    scanf("%s%s",first_num,second_num);
    moveToEnd(first_num,81);moveToEnd(second_num,81);
    convertInt(first_num);convertInt(second_num);
    if(compare(first_num,second_num,81)){
        SUB(first_num,second_num,sub);
                for (int i = 80;; i--) {
        if (sub[i] != '\0') {
            for (; i >= 0; i--) {
                printf("%d", sub[i]);
            }
            break;
        }
    }
    }
    else{ SUB(second_num,first_num,sub);
        printf("-");
        for (int i = 80;; i--) {
        if (sub[i] != '\0') {
            for (; i >= 0; i--) {
                printf("%d", sub[i]);
            }
            break;
        }
    }
    }
}