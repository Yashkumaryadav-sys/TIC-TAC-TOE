#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<string.h>
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif
char arr[9],player1,player2,currentplayer,nameplayer1[10],nameplayer2[10],winner,playagain; 
int i,j,k,choice,ind,res,count,player1_score,player2_score,draw_score,game_mode;
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
int smart_move(char arr[],char computer,char player)
{
    int combo[8][3]= {
        {0,1,2},
        {3,4,5},
        {6,7,8},
        {0,3,6},
        {1,4,7},
        {2,5,8},
        {0,4,8},
        {2,4,6}
    };
    for(int m=0;m<8;m++)  // ye fuction ye check karega ki computer jeet sakta hai ya nahi
    {
        int a=combo[m][0] , b=combo[m][1] , c=combo[m][2];
        int computercount=0,emptyindex=-1;
        if(arr[a] == computer)
        {
            computercount++;
        }
        else if(arr[a] != player)
        {
            emptyindex = a;
        }
        if(arr[b] == computer)
        {
            computercount++;
        }
        else if (arr[b] != player)
        {
            emptyindex = b ;
        }
        if(arr[c] == computer)
        {
            computercount++;
        }
        else if (arr[c] != player)
        {
            emptyindex = c;
        }
        if(computercount == 2 && emptyindex != -1)
        {
            return emptyindex;
        }
    }
    for(int m=0;m<8;m++) // ye function player ko block karega har possible ways se.
    {
        int a=combo[m][0], b=combo[m][1], c=combo[m][2];
        int playercount=0, emptyInd=-1;

        if(arr[a] == player) 
        {
            playercount++;
        }
        else if(arr[a]!=computer)
        {
             emptyInd=a;
        }
        if(arr[b]==player)
        {
             playercount++;
        }
        else if(arr[b]!=computer) 
        {
            emptyInd=b;
        }
        if(arr[c]==player) 
        {
            playercount++;
        }
        else if(arr[c]!=computer)
        {
             emptyInd=c;
        }

        if(playercount==2 && emptyInd!=-1)
        {
            return emptyInd;
        }
    }
    if(arr[4] != 'X' && arr[4] != 'O')
    {
        return 4;
    }
    int r;
    do
    {
        r=rand()%9;
    }
    while (arr[r] == 'X' || arr[r] == 'O');
    return r;
    
}

int main()
{
 do
 {   
 printf("\n===============================\n");
 printf("==WELCOME TO TIC TAC TOE GAME==\n");
 printf("===============================\n");
 printf("\n");
 printf("\n===================== \n");
 printf("======GAME MODE====== \n");
 printf("===================== \n");
 printf("1.Player vs Player \n");
 printf("2.Player vs Computer \n");
 printf("===================== \n");
    do
{
    printf("Enter Choice: (1/2): ");
    res = scanf("%d",&game_mode);
    while(getchar()!='\n');
    if(res != 1 || (game_mode != 1 && game_mode != 2))
    {
        printf("Invalid! Please enter 1 or 2 only.\n");
        game_mode = 0;
    }
}
while(game_mode != 1 && game_mode != 2);
 if(game_mode == 1)
 {
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
if(player1 == 'X')
{
    currentplayer = player1;
}
else
{
    currentplayer = player2;
}
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
}
else if (game_mode == 2)
{
    printf("Enter your name:");
    scanf("%s",nameplayer1);
    nameplayer1[0]=toupper(nameplayer1[0]);
    nameplayer2[0]=toupper(nameplayer2[0]); 
    strcpy(nameplayer2,"Computer");
    do
    {
        printf("Enter your choice %s 'X' 'O': \n",nameplayer1);
        scanf(" %c",&player1);
    }
    while(player1 != 'X' && player1 != 'O' && player1 != 'x' && player1 != 'o');
    player1=toupper(player1);
    if (player1 == 'X')
    {
        player2 = 'O';
    }
    else
    {
        player2 = 'X';
    }
    player1_score =0;
    player2_score=0;
    draw_score=0;
    srand(time(NULL));
    while(1)
{
    for(k=0;k<9;k++)
        arr[k]=k+'1';
    count=0; 
    if(player1 == 'X')
    {
    currentplayer = player1;
    }
else
{
    currentplayer = player2;
}

    while(1)
    {
        system(CLEAR);
        print_board(arr);

        if(currentplayer == player1)
        {
            printf("%s's turn:\n",nameplayer1);
            printf("Enter your choice %s:",nameplayer1);
            res=scanf("%d",&choice);
            while(getchar()!='\n');
            if(res!=1)
            {
                printf("Invalid input! Please enter a number only.\n");
                continue;
            }
            if(choice<1||choice>9)
            {
                printf("Invalid! Enter between 1 to 9\n");
                continue;
            }
            ind=choice-1;
            if(arr[ind]=='X'||arr[ind]=='O')
            {
                printf("Cell already taken! Try again.\n");
                continue;
            }
        }
        else
        {
            ind = smart_move(arr, player2, player1);
            printf("Computer chose: %d\n", ind+1);
        }

        arr[ind]=currentplayer;
        count++;
        winner=check_win(arr);

        if(winner==player1)
        {
            print_board(arr);
            printf("%s wins!\n",nameplayer1);
            break;
        }
        else if(winner==player2)
        {
            print_board(arr);
            printf("Computer wins!\n");
            break;
        }
        else if(count==9)
        {
            print_board(arr);
            printf("It's a draw!\n");
            break;
        }

        if(currentplayer==player1)
            currentplayer=player2;
        else
            currentplayer=player1;
    }

    if(winner==player1)
        player1_score++;
    else if(winner==player2)
        player2_score++;
    else
        draw_score++;

    printf("\n===================\n");
    printf("====SCORE BOARD====\n");
    printf("===================\n");
    printf("%s:%d\n",nameplayer1,player1_score);
    printf("Computer:%d\n",player2_score);
    printf("Draw:%d\n",draw_score);
    printf("===================\n");

    printf("Play Again?(Y/N)\n");
    scanf(" %c",&playagain);
    playagain=toupper(playagain);
    if(playagain=='N')
        break;
}

printf("\n===================\n");
printf("====FINAL SCORE====\n");
printf("===================\n");
if(player1_score>player2_score)
{
    printf("%s is a Winner!\n",nameplayer1);
    printf("By %d Points\n",player1_score-player2_score);
    printf("Thanks for playing!\n");
}
else if(player2_score>player1_score)
{
    printf("Computer is a Winner!\n");
    printf("By %d Points\n",player2_score-player1_score);
    printf("Thanks for playing!\n");
}
else
{
    printf("Match Draw!\n");
    printf("Thanks for playing!\n");
}
printf("===================\n");
}
printf("\n");
printf(" ----------------------\n");
printf(" Start new game? (Y/N): \n ");
printf("-----------------------\n");
        scanf(" %c", &playagain);
        playagain = toupper(playagain);
        system(CLEAR);
    }
    while(playagain == 'Y');
    printf("Thanks for playing!\n");
    system(CLEAR);

 return 0;
}