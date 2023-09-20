#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void print_score(char score[])
{
    printf("\n\
      %c :  %c  : %c     \n\
     ---+-----+---       \n\
      %c :  %c  : %c     \n\
     ---+-----+---       \n\
      %c :  %c  : %c     \n\
    \n",
           score[0], score[1], score[2], score[3], score[4], score[5], score[6], score[7], score[8]);
}

bool isEven(float x)
{
    float y = x / 2;
    int z = y;
    if (y - z == 0)
    {
        return (true);
    }
    else
    {
        return (false);
    }
}

void setWinner(char a, char b, char c, char *winner)
{
    bool match = a == b;
    match &= b == c;
    if (match == true)
    {
        *winner = a;
    }
}

char getWinner(char *placing)
{
    char winner;

    // for each box on the top row...
    for (int clm = 0; clm < 3; clm++)
    {
        setWinner(placing[clm], placing[clm + 3], placing[clm + 6], &winner);
    }

    // for each box in the left column...
    for (int row = 0; row < 3; row += 3)
    {
        // check if the two boxes to the right match
        setWinner(placing[row], placing[row + 1], placing[row + 2], &winner);
    }

    // check the diagonals independently... there are no patterns
    setWinner(placing[0], placing[4], placing[8], &winner);
    setWinner(placing[6], placing[4], placing[2], &winner);
    return winner;

    // for (int q = 1; q < 5; q++) // going up by q 0 + 1= 1, 1 + 1 = 2.
    // {
    //     for (int e; e < 6; e++) // starting at e
    //     {

    //         for (int w; w < 9; w++)
    //         {
    //             // starting at e going up by q
    //             // e + q =
    //         }
    //     }
    // }3
}

void takeTurn(char score[], char letter)
{
    while (true)
    {
        char in[6];
        int spot;
        spot = atoi(gets(in));

        // boundary check
        if (spot < 1 && spot > 9)
        {
            printf("try again - pick 1-9");
        }
        // make sure the square is unused
        else if ((score[spot] != 'X') && (score[spot] != 'O'))
        {
            score[spot] = letter;
            break;
        }
        else
        {
            printf("try again");
        }
    }
}

int main(void)
{
    float turn = 3;
    char score[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
    char winner = '-';

    print_score(score);

    while (true)
    {
        if (isEven(turn) == true)
        {
            printf("pick one number on the table to change to O\n");
            takeTurn(score, 'O');
            print_score(score);
        }
        else
        {
            printf("pick one number on the table to change to X\n");
            takeTurn(score, 'X');
            print_score(score);
        }
        winner = getWinner(score);
        if (winner != '-')
            cout << "The winner is " << winner;
        turn += 1;
        if (turn > 11)
        {
            break;
        }
    }

    return 0;
}
// x / (x/2) == 2