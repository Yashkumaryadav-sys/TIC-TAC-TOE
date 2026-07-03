#include<stdio.h>
#include<conio.h> 
#include<stdlib.h>
#include<ctype.h>
char arr[9],player1,player2,currentplayer,nameplayer1[10],nameplayer2[10],winner; 
int i,j,k,choice,ind,res;
void print_board(char arr[])
{
  for(i=0;i<3;i++)
 {
    for(j=0;j<3;j++)
    {
        int ind=i*3+j;
         printf(" %c ",arr[ind]);
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
}
char check_win(char arr[])
{
    if (arr[0]==arr[1] && arr[1]==arr[2])
    {
        return arr[0];
    }
    else if (arr[3]==arr[4] && arr[4]==arr[5])
    {
        return arr[3];
    }
    else if (arr[6]==arr[7] && arr[7]==arr[8])
    {
        return arr[6];
    }
    else if (arr[0]==arr[3] && arr[3]==arr[6])
    {
        return arr[0];
    }
    else if (arr[1]==arr[4] && arr[4]==arr[7])
    {
        return arr[1];
    }
    else if (arr[2]==arr[5] && arr[5]==arr[8])
    {
        return arr[2];
    }
    else if (arr[0]==arr[4] && arr[4]==arr[8])
    {
        return arr[0];
    }
    else if (arr[2]==arr[4] && arr[4]==arr[6])
    {
        return arr[2];
    }
    else
    {
        return ' ';
    }
}
int main()
{
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
    print_board(arr);
    if (currentplayer == player1)
    {
    printf("%s's turn: \n",nameplayer1);
    printf("Enter your choice %s:" , nameplayer1);
    res=scanf("%d",&choice);
    while(getchar() != '\n');
    if(res != 1)
    {
    printf("Invalid input! Please enter a number only.\n");
    continue;
    }
}
    else
    {
    printf("%s's turn: \n",nameplayer2);
    printf("Enter your choice %s:" , nameplayer2);
    res=scanf("%d",&choice);
    while(getchar() != '\n');
    if(res != 1)
    {
    printf("Invalid input! Please enter a number only.\n");
    continue;
    }
    }

    if(choice < 1 || choice > 9)
    {
        printf("Invalid! Enter between no 1 to 9 \n");
        continue;
    }
    ind = choice - 1;

if(arr[ind] == 'X' || arr[ind] == 'O')
{
    printf("Cell already taken! Try again.\n");
    continue;
}
arr[ind] = currentplayer;
winner=check_win(arr);
if(winner==player1)
{
    print_board(arr);
    printf("%s wins!",nameplayer1);
    break;
}
else if(winner==player2)
{
    print_board(arr);
    printf("%s wins!",nameplayer2);
    break;
}
 
if(currentplayer == player1)
{
    currentplayer = player2;
}
else
{
    currentplayer = player1;
}
 }
 return 0;
}