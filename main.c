#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
char boardGame[4][4]= {};
char p, c;

bool checkChance(char k ){
    int i ,j , cnt=0;
     for(i=1 ; i<4 ; i++){
                cnt= 0;
            for(j=1 ; j<4 ; j++){
                if(boardGame[i][j] == k){
                    cnt++;
                }
            }
            if (cnt==2){
                if (boardGame[i][1]==' '){
                     boardGame[i][1]=c;
                     return true;
                }

                if (boardGame[i][2]== ' '){
                    boardGame[i][2]=c;
                    return true;
                }
                if(boardGame[i][3]== ' '){
                    boardGame[i][3]=c;
                    return true;
                }
            }
        }
        //1.2 col check
         for(i=1 ; i<4 ; i++){
                cnt= 0;
            for(j=1 ; j<4 ; j++){
                if(boardGame[j][i] == k){
                    cnt++;
                }
            }
            if (cnt==2){
                 if (boardGame[1][i]==' '){
                     boardGame[1][i]=c;
                     return true;
                }

                if (boardGame[2][i]== ' '){
                    boardGame[2][i]=c;
                    return true;
                }
                if(boardGame[3][i]== ' '){
                    boardGame[3][i]=c;
                    return true;
                }
            }
        }
        //1.3 diagonal check
        if (boardGame[3][3] == boardGame[1][1]  || boardGame[3][3] == boardGame[2][2] || boardGame[2][2] == boardGame[1][1]){
            if (boardGame[3][3] == k || boardGame[1][1]== k ){
                if (boardGame[3][3]==' '){
                    boardGame[3][3]=c;
                    return true;
                }
                if (boardGame[1][1]==' '){
                    boardGame[1][1]=c;
                    return true;
                }
                if (boardGame[2][2]==' '){
                    boardGame[2][2]=c;
                    return true;
                }

            }
        }

        if (boardGame[1][3] == boardGame[3][1]  || boardGame[1][3] == boardGame[2][2] || boardGame[2][2] == boardGame[3][1]){
            if (boardGame[1][3] == k || boardGame[3][1]== k ){
                if (boardGame[3][1]==' '){
                    boardGame[3][1]=c;
                    return true;
                }
                if (boardGame[1][3]==' '){
                    boardGame[1][3]=c;
                    return true;
                }
                if (boardGame[2][2]==' '){
                    boardGame[2][2]=c;
                    return true;
                }
            }
        }
    return false;
}
int selectPlayer()
{
    printf("\t Please select a player\n\t1-X\n\t2-O\n\t");
    int player;
b:
    scanf("%d", &player);
    if (player!=1 && player!=2)
    {
        printf("invalid choice\n");
        goto b;
    }
    return player;
}
void printBoard()
{
    int i, j;
    printf("\t");
    for(i=1 ; i<=3 ; i++)
    {
        for(j =1 ; j<=3 ; j++)
        {
            if (j!= 1)
            {
                printf("|%c", boardGame[i][j]);
            }

            else
            {
                printf("%c", boardGame[i][j]);
            }

        }
        printf("\n\t");
    }
    printf("\n\n");
}
void initializeBoard()
{
    int i, j;
    for(i=1 ; i<=3 ; i++)
    {
        for(j =1 ; j<=3 ; j++)
        {
            boardGame[i][j] =' ';
        }
    }
}
void ComputerTurn ()
{       int i, j, cnt=0;
    // 1- check if computer has 2 in raw & third spot free
        bool check ;
       check = checkChance(c);
       if(check)
        return ;
    // 2- check if player has 2 in row & third spot is free
        check = checkChance(p);
        if (check){
            return ;
        }
    // 3- if center free place in it
        if (boardGame[2][2] == ' '){
            boardGame[2][2] = c;
            return ;
        }

    // 4- If player places on a corner place on the opposite corner
        if (boardGame[1][1] == p && boardGame[3][3] == ' '){
            boardGame[3][3] = c;
            return;
        }
        if (boardGame[3][3] == p && boardGame[1][1] == ' '){
            boardGame[1][1] = c;
            return;
        }
        if (boardGame[1][3] == p && boardGame[3][1] == ' '){
            boardGame[3][1] = c;
            return;
        }
        if (boardGame[3][1] == p && boardGame[1][3] == ' '){
            boardGame[1][3] = c;
            return;
        }

    // 5- choose any free corner
        if ( boardGame[3][3] == ' '){
            boardGame[3][3] = c;
            return;
        }
        if (boardGame[1][1] == ' '){
            boardGame[1][1] = c;
            return;
        }
        if (boardGame[3][1] == ' '){
            boardGame[3][1] = c;
            return;
        }
        if (boardGame[1][3] == ' '){
            boardGame[1][3] = c;
            return;
        }
    // 6- choose any free side
         if (boardGame[1][2] == ' '){
            boardGame[1][2] = c;
            return;
        }
         if (boardGame[3][2] == ' '){
            boardGame[3][2] = c;
            return;
        }
         if (boardGame[2][1] == ' '){
            boardGame[2][1] = c;
            return;
        }
         if (boardGame[2][3] == ' '){
            boardGame[2][3] = c;
            return;
        }

}
void PlayerTurn()
{
    printf(" Enter the number of the cell: ");
    int turn;
p:
    scanf("%d", &turn);
    if (turn %3==0)
    {
        if(boardGame[turn/3][3] ==' ')
        {
            boardGame[turn/3][3]= p;
        }
        else
        {
            printf("Occupied Cell choose again: ");
            goto p;
        }
    }
    else
    {
        if (boardGame[turn/3 +1][turn%3]==' ')
            boardGame[turn/3 +1][turn%3]=p;
        else
        {
            printf("Occupied Cell choose again: ");
            goto p;
        }
    }
}
bool checkStatus(char playerLetter)
{
    bool check=true;
    int i , j;
    // check win
    //1- Row check
    for(i=1 ; i<=3 ; i++){
            check=true;
        for(j=1 ; j<=3 ; j++){
            if (boardGame[i][j] != playerLetter ){
                check=false;
                break;
            }
        }
        if(check){
            printf("%c Wins\n\n" , playerLetter);
            return false;
        }
    }

    //2- Column check
    for(i=1 ; i<=3 ; i++){
            check=true;
        for(j=1 ; j<=3 ; j++){
            if (boardGame[j][i] != playerLetter ){
                check=false;
                break;
            }
        }
        if(check){
            printf("%c Wins" , playerLetter);
            return false;
        }
    }

    // 3- diagonal check

    if (boardGame[1][1] == playerLetter && boardGame[1][1] == boardGame[2][2]  && boardGame[2][2] == boardGame[3][3]){
        printf("%c Wins" , playerLetter);
            return false;
    }
    if (boardGame[1][3] == playerLetter && boardGame[1][3] == boardGame[2][2]  && boardGame[2][2] == boardGame[3][1]){
        printf("%c Wins" , playerLetter);
            return false;
    }

    // Check Draw
    check=true;
    for(i=1 ; i<=3 && check; i++){
        for (j=1 ; j<=3 ; j++){
            if (boardGame[i][j] == ' '){
                check=false;
                break;
            }
        }
    }
    if (check){
        printf("Game Draw");
        return false;
    }
    return true;
}

void playGame(int player)
{
    int turn;
    p = (player == 2) ? 'O' : 'X';
    c = (player == 1) ? 'O' : 'X';
    if(player == 1)
    {
        printf("\tX is selected.\n\t");
        PlayerTurn();
        printBoard();
    }

    bool f = true;
    while (f)
    {
        ComputerTurn();
        printBoard();
        f=checkStatus(c);
        if (!f)
            break;
        PlayerTurn();
        printBoard();
        f=checkStatus(p);

    }
}



int main()
{
    memset(boardGame, '\0', sizeof(boardGame));
  b:  printf("\tWelcome to X-O board game\n\tPlease select an option:\n\t1-Start new game\n\t2-Exit\n\t");
    int x ;
    int player;
a:
    scanf("%d", &x);
    if(x==1)
    {
        player = selectPlayer();
    }
    else if (x==2)
    {
        return 0;
    }
    else
    {
        printf("\tinvalid choice, please choose again :\n\t");
        goto a;
    }
    initializeBoard();
    printBoard();
    playGame(player);
    goto b;
}
