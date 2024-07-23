#include <stdio.h>

void DisplayGrid(int Grid[][3]);
void GetUserInput(int num[], int Grid[][3]);
void CheckWinCondition(int Grid[][3],int *win, int*over);
void CheckWinConditioncol(int Grid[][3],int *win, int*over, int ncol);
void CheckWinConditionrow(int Grid[][3],int *win, int*over, int nrow);

int main (void)
{
    int turn=1,over=0,win=0;
    int Grid[3][3] = {0};
    int Numbers[9]={1,2,3,4,5,6,7,8,9};

    while(over==0)
    {   
        DisplayGrid(Grid);
        if(turn==1)
        {
            fprintf(stdout,"\nPlayer 1's turn\n\n");
            GetUserInput(Numbers,Grid);
        }
        else
        {
            fprintf(stdout,"\nPlayer 2's turn\n\n");
            GetUserInput(Numbers,Grid);
        }

        CheckWinCondition(Grid,&win,&over);

        if(turn==1)
        {
            turn=0;
        }
        else
        {
            turn=1;
        }
    }

    DisplayGrid(Grid);

    if (turn == 1)
    {
        if (win == 1)
        {
            printf("\n\nPlayer 2 Won!");
        }
        else
        {
            printf("\n\nPlayer 1 Won!");
        }
    }

    if (turn == 0)
    {
        if (win == 1)
        {
            printf("\n\nPlayer 1 Won!");
        }
        else
        {
            printf("\n\nPlayer 2 Won!");
        }
    }


}

void DisplayGrid(int Grid[][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(Grid[i][j]==0)
            {
                fprintf(stdout,"\t_\t");
            }
            else
            {
                fprintf(stdout,"\t%d\t",Grid[i][j]);
            }
        }
        fprintf(stdout,"\n");
    }
}

void GetUserInput(int num[], int Grid[][3])
{
    int xcoord=-1,ycoord=-1,occ=1;
    int number,used;

    while(xcoord<0 || xcoord>2 || ycoord<0 || ycoord>2 || occ == 1)
    {
        fprintf(stdout,"Please enter VALID Coordinates (e.g. 1 1, 2 2, etc.): ");
        fscanf(stdin,"%d %d",&xcoord,&ycoord);

        xcoord--;ycoord--;

        if(Grid[xcoord][ycoord]==0)
        {
            occ = 0;
        }
        else
        {
            occ = 1;
        }

    }

    while(number<1 || number > 9 || used == 1)
    {
        fprintf(stdout,"Please Input a Number between 1 to 9: ");
        fscanf(stdin,"%d",&number);
        if(num[number-1]==0)
        {
            used = 1;
        }
        else
        {
            used = 0;
            Grid[xcoord][ycoord]=num[number-1];
            num[number-1]=0;
        }
    }
}

void CheckWinCondition(int Grid[][3],int *win, int*over)
{
    CheckWinConditionrow(Grid,&*win, &*over,0);
    CheckWinConditionrow(Grid,&*win, &*over,1);
    CheckWinConditionrow(Grid,&*win, &*over,2);
    CheckWinConditioncol(Grid,&*win, &*over,0);
    CheckWinConditioncol(Grid,&*win, &*over,1);
    CheckWinConditioncol(Grid,&*win, &*over,2);
}

void CheckWinConditionrow(int grid[][3],int *win, int*over, int nrow)
{
    if (grid[nrow][0] != 0 && grid[nrow][1] != 0 && grid [nrow][2] != 0)
    {
        if (grid [nrow][0] + grid[nrow][1] + grid[nrow][2] < 15)
        {
            *over = 1;
            *win = 0;
        }
        else if (grid [nrow][0] + grid[nrow][1] + grid[nrow][2] == 15)
        {
            *over = 1;
            *win = 1;
        }
    }
}

void CheckWinConditioncol(int grid[][3],int *win, int*over, int ncol)
{
    if (grid[0][ncol] != 0 && grid[1][ncol] != 0 && grid [2][ncol] != 0)
    {
        if (grid [0][ncol] + grid[1][ncol] + grid[2][ncol] < 15)
        {
            *over = 1;
            *win = 0;
        }
        else if (grid [0][ncol] + grid[1][ncol] + grid[2][ncol] == 15)
        {
            *over = 1;
            *win = 1;
        }
    }
}