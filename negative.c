#include <stdio.h>
int PrintImage(int arr[][256],int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            arr[i][j]=Convert2Negative(arr[i][j]);
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
int Convert2Negative(int pixel){
    return 255-pixel;
}
int main(){
    int arr[256][256]={0},size;
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    PrintImage(arr,size);

}