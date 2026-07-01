#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
 int arr[9],k;  //stage 1.
 for(k=0;k<9;k++){
     arr[k]=k+1;
 }
 int i,j;
 for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        int index=i*3+j;
         printf(" %d ",arr[index]);
         if(j!=2){
         printf("|");
         }
          
         }
         printf("\n");
          if(i!=2){
        printf("-----------");
     printf("\n");
          }
    
     
    }
   
 return 0;
}