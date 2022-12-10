#include <stdio.h>
#include <math.h>
int main(){
    char word[6]="";scanf("%s",word);int cntr=0,result;
    for(int i=0;i<6;i++){
        if(word[i]=='a'||word[i]=='i'||word[i]=='e'||word[i]=='o'||word[i]=='u') cntr++;
    }
    result=pow(2,cntr);printf("%d",result);
}
