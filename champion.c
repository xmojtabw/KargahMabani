#include <stdio.h>
int main() {
    int number_of_teams=0, team, lowest;
    scanf("%d%d", &number_of_teams, &team); int temp;
    int * score_of_teams=malloc(110*sizeof(int)); 
    int check;

    for (int i = 0; i < number_of_teams; i++) {

        scanf("%d", (score_of_teams+i));

    }

    

    for (int i = 0; i <number_of_teams; i++) {
        lowest = 200;
        for (int j = i; j < number_of_teams; j++) {
            if (lowest > *(score_of_teams + j)) {
                lowest = *(score_of_teams + j);
                temp = j;
            }
        }
        *(score_of_teams + temp) = *(score_of_teams + i); *(score_of_teams + i) = lowest;
    }
  //  for (int i=0;i<number_of_teams;i++){
 //       printf("%d ",*(score_of_teams+i));
 //   }puts(" ");
    
    temp =number_of_teams;
    for (int i = 0; i < temp; i++) {
        if (*(score_of_teams + i) < *(score_of_teams+ (temp-team))||(*(score_of_teams + i)<1))number_of_teams--;
    }
    printf("%d",number_of_teams);


}
