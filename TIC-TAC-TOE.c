#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif
char arr[9],player1,player2,currentplayer,nameplayer1[10],nameplayer2[10],winner,playagain; 
int i,j,k,choice,ind,res,count,player1_score,player2_score,draw_score;
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
 printf("\n===============================\n");
 printf("==WELCOME TO TIC TAC TOE GAME==\n");
 printf("===============================\n");
 printf("Enter the name of the player1:");
 scanf("%s",nameplayer1);
 printf("Enter the name of the player2:");
 scanf("%s",nameplayer2);
 player1_score=0;
 player2_score=0;
 draw_score=0;
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
 printf("=============\n");
 printf("====BOARD====\n");
 printf("=============\n");

 printf("\n");
while (1)
{
 for(k=0;k<9;k++)
 {
     arr[k]=k+'1';
 }
 count=0;
 currentplayer = player1;
 while(1)
 { 
    system(CLEAR);
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
count+=1;
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
else if (count == 9)
{
    print_board(arr);
    printf("It's a draw ! \n");
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
 if(winner == player1)
 {
    player1_score++;
 }
 else if(winner == player2)
 {
    player2_score++;
 }
 else
 {
    draw_score++;
 }
 printf("\n===================\n");
 printf("====SCORE BOARD====\n");
 printf("===================\n");
 printf("%s:%d \n",nameplayer1,player1_score);
 printf("%s:%d \n",nameplayer2,player2_score);
 printf("Draw:%d \n",draw_score);
 printf("\n===================\n");
 printf("Play Again:(Y/N) \n");
 scanf(" %c",&playagain);
 playagain=toupper(playagain);
 if(playagain == 'N')
 {
    break;
 }
 }
 printf("\n===================\n");
 printf("====FINAL SCORE====\n");
 printf("===================\n");
 if(player1_score > player2_score)
 {
    printf("%s is a winner! \n",nameplayer1);
    printf("By %d Points \n",player1_score - player2_score);
    printf("Thanks for playing! \n");
 }
 else if (player2_score > player1_score)
 {
    printf("%s is a winner! \n",nameplayer2);
    printf("By %d Points \n",player2_score - player1_score);
    printf("Thanks for playing! \n");
 }
 else{
    printf("Match draw! \n");
    printf("Thanks for playing! \n");
 }
 printf("===================\n");
 return 0;
}