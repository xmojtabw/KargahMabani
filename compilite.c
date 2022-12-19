#include <stdio.h>
int poww(int b){
    int a=2;
    for(int i=0;i<b-1;i++){
        a*=2;
    }
    return a;
}
char *change(char *arr){
    for(int i=0,x=1;i<16;i++,x++){
        for(int j=0;j<poww(x);j++){
        if (arr[j]==0)arr[j+(poww(x))]=1;
        }
    }
    return arr;
}
int main(){
    char numbers[140000]={0};numbers[0]=1;numbers[1]=0;change(numbers);int R=0,L=0;
    scanf("%d%d",&L,&R);
    for(int i=L;i<=R;i++){
        printf("%d",numbers[i-1]);
    }
}