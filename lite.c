#include <stdio.h>
int main(){
    char colors[5]="";int cntrG=0,cntrR=0,cntrY=0;
    scanf("%s",colors);
    for(int i=0;i<5;i++){
        if(colors[i]=='G')cntrG++;
        else if(colors[i]=='R')cntrR++;
        else cntrY++;
    }
    if((cntrG<1)||(cntrR>2)||(cntrY>1&&cntrR>1))
        puts("nakhor lite");
    else puts("rahat baash");
}