#include <stdio.h>
int main(){
    char first_word[50]="",second_word[50]="",last_char;
    scanf("%s",first_word);scanf("%s",second_word);
    for(int i=0;second_word[i]!='\0';i++){
        last_char=second_word[i];
    }
    if(first_word[0]==last_char)puts("YES");
    else puts("NO");
}
