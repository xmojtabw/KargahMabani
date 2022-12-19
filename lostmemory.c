#include <stdio.h>
int *f(int number_n){
    int *numbers=malloc(100*sizeof(int));
    for(int i=0;i<number_n;i++){
        *(numbers+i)=i*i;
    }
    return numbers;
}
int main(){
    int n;
    scanf("%d", &n);
    int* b = f(n);
    for(int i = 0; i < n; i++){
        printf("%d ", b[i]);
    }
}