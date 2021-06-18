#include <bits/stdc++.h>
 
using namespace std;

int b[9][9] ; 

bool is_valid(int row, int col, int k)
{
    int b_row = (row/3) * 3 ; 
    int b_col = (col/3) * 3 ; 
    for(int i = 0 ; i < 9 ; i++)
    {
        if(b[row][i] == k or b[i][col] == k or b[b_row+i/3][b_col+i%3] == k)
            return false ;
    }
    
    return true ; 
}

bool solve_sudoku()
{
    for(int i = 0 ; i < 9 ; i++)
    {
        for(int j = 0 ; j < 9 ; j++)
        {
            if(b[i][j] == 0)
            {
                for(int k = 1 ; k <= 9 ; k++)
                {
                    if(is_valid(i, j, k))
                    {
                        b[i][j] = k ; 
                        if(solve_sudoku())
                            return true ; 
                        b[i][j] = 0 ;
                    }
                }
                return false ;
            }
        }
    }
    
    return true ; 
}

int main()
{
    for(int i = 0 ; i < 9 ; i++)
    {
        for(int j = 0 ; j < 9 ; j++)
        {
            cin >> b[i][j] ; 
        }
    }
    
    
    if(solve_sudoku())
    {
        for(int i = 0 ; i < 9 ; i++)
        {
            for(int j = 0 ; j < 9 ; j++)
            {
                cout << b[i][j] << " " ;
            }
            cout << endl ; 
        }
    }
    else
        cout << "Not Solved" ; 
}