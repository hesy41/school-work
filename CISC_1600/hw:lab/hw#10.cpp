//Siyi He
//Dec. 2, 2020
//R02- hw#10: tic-tac-toe

#include <iostream>
#include <cstdlib>
using namespace std;

//varible 
const int MAX_ROWS = 3;
const int MAX_COLMS = 3;
char ttt[MAX_ROWS][MAX_COLMS]= {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

//prototype
void displayTTT(char (*q)[MAX_COLMS], int  row, int  col);
void replace (char (*t)[MAX_COLMS], int  row, int  col, char pl);
bool win (char (*t)[MAX_COLMS], char pl);

int main ()
{
    // varible 
    char player;
    int turn, number;

    //processing 
    for (turn = 1; turn <= 9; turn ++)
    {
        if (turn%2 == 1)
            player = 'X';
        else
            player = 'O';
        
        displayTTT (ttt,MAX_ROWS,MAX_COLMS);
        replace (ttt, MAX_ROWS, MAX_COLMS, player);

        if (turn >= 5)
        {
            if (win (ttt, player) == true)
            {
                cout << "Congraluations! Player" << player << " is the winner!" << endl;
                displayTTT (ttt,MAX_ROWS,MAX_COLMS);
                break;
            }
        }
        if (turn == 9)
        {
            cout << "It is a TIE" << endl;
            displayTTT (ttt,MAX_ROWS,MAX_COLMS);
        }
    }
    return 0;
}

//function definition 
void displayTTT(char (*q)[MAX_COLMS], int  row, int  col)
{
    int  i, j;
    for(i = 0; i < row; i++ )
    {
        for( j=0; j<col ; j++)
        {
            cout<<"\t"<< *(*(q + i)+j); 
        }

        cout<<"\n";
    }  
    cout<<"\n";
}

//function def
void replace (char (*t)[MAX_COLMS], int  row, int  col, char pl)
{
    int move, r, c;

    cout << "player" << pl << " what is your move? (use number 1-9): ";
    cin  >> move;

    move --;
    row = move / 3;
    col = move % 3;

    t[row][col] = pl;
}

//function def
bool win (char (*t)[MAX_COLMS], char pl)
{
    int i, j;
    for (i =0; i<MAX_ROWS; i++)
    {
        if (t[i][0]==t[i][1] && t[i][1]==t[i][2])
            return true;
    }

    for (j=0; j<MAX_COLMS; j++)
    {
        if (t[0][j]==t[1][j] && t[1][j]==t[2][j])
            return true;
    }

    if (t[0][0]==t[1][1] && t[1][1]==t[2][2])
        return true;
    else if (t[0][2]==t[1][1] && t[1][1]==t[2][0])
        return true;
    else
        return false;
    
}