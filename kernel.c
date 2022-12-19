#include <stdio.h>
#include <stdlib.h>
int main(void){
    int size_of_mat=0;
    scanf("%d",&size_of_mat);
    int **mat=(int**)malloc(size_of_mat*sizeof(int*));
    for(int i=0;i<size_of_mat;i++){
        mat[i]=(int*)malloc(size_of_mat*sizeof(int));
        for(int j=0;j<size_of_mat;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    int size_of_ker=0;
    scanf("%d",&size_of_ker);
    int **ker=(int**)malloc(size_of_ker*sizeof(int*));
    for(int i=0;i<size_of_ker;i++){
        ker[i]=(int*)malloc(size_of_ker*sizeof(int));
        for(int j=0;j<size_of_ker;j++){
            scanf("%d",&ker[i][j]);
        }
    }
    
    int k=(size_of_ker-1)/2;
    if(size_of_ker%2==0){
        k=(size_of_mat+2)/2;
    }

    int **matk=(int**)malloc(size_of_mat*sizeof(int*));
    for(int i=0;i<size_of_mat;i++){
        matk[i]=(int*)malloc(size_of_mat*sizeof(int));
    }
    for(int i=0;i<size_of_mat;i++){
        for(int j=0;j<size_of_mat;j++){
            if(i<k||j<k||i>=(size_of_mat-k)||j>=(size_of_mat-k)){
                matk[i][j]=0;
            }
            else{
                int sum=0;
                for(int x=0;x<size_of_ker;x++){
                    for(int y=0;y<size_of_ker;y++){
                        sum+=mat[i-k+x][j-k+y]*ker[x][y];
                    }
                }
                if (sum>255){
                sum=255;
                }
                matk[i][j]=sum;
            }
        }
    }
    


    for(int i=0;i<size_of_mat;i++){
        for(int j=0;j<size_of_mat;j++){
            printf("%d ",matk[i][j]);
        }
        printf("\n");
    }

}