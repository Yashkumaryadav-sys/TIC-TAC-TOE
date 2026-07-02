#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
 char arr[9],player1,player2,currentplayer,nameplayer1[10],nameplayer2[10];  //stage 2.
 int i,j,k,choice,index;
 printf("Enter the name of the first player1:");
 scanf("%s",nameplayer1);
 printf("Enter the name of the player2:");
 scanf("%s",nameplayer2);
 nameplayer1[0] = toupper(nameplayer1[0]);
 nameplayer2[0] = toupper(nameplayer2[0]);
 do
 {
 printf("Enter your choice %s 'X' 'O': \n",nameplayer1);
 scanf(" %c",&player1);
 }
 while(player1 != 'x' && player1 != 'o' && player1 != 'X' && player1 != 'O');
 
 player1 = toupper(player1);
 if(player1 == 'X')
    player2 = 'O';
else
    player2 = 'X';

 printf("%s:%c \n",nameplayer1,player1);
 printf("%s:%c \n",nameplayer2,player2);

 currentplayer=player1;

 printf("\n");
 printf("Board: \n");

 for(k=0;k<9;k++)
 {
     arr[k]=k+'1';
 }
 while(1)
 {
 for(i=0;i<3;i++)
 {
    for(j=0;j<3;j++)
    {
        int index=i*3+j;
         printf(" %c ",arr[index]);
         if(j!=2)
         {
         printf("|");
         }
        }
        printf("\n");
        if(i!=2)
        {
        printf("-----------");
        printf("\n");
        }
    }
    printf("\n");

    if (currentplayer == player1)
    printf("%s's turn: \n",nameplayer1);
    else
    printf("%s's turn: \n",nameplayer2);
    printf("Enter your choice:");
    scanf("%d",&choice);

    if(choice < 1 || choice > 9)
    {
        printf("Invalid! Enter between no 1 to 9 \n");
        continue;
    }
    index = choice - 1;

if(arr[index] == 'X' || arr[index] == 'O')
{
    printf("Cell already taken! Try again.\n");
    continue;
}
arr[index] = currentplayer;

if(currentplayer == player1)
    currentplayer = player2;
else
    currentplayer = player1;
}
    return 0;
}