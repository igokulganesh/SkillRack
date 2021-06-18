#include <bits/stdc++.h>
 
using namespace std;

int n ; 

vector<bool> row, col ; // , dia_1, dia_2 ; 

bool chech_dia(vector<vector<int> > & b, int x, int y)
{
    for(int i = x+1, j = y+1 ; i < n and j < n ; i++, j++)
    {
        if(b[i][j])
            return false ; 
    }
    
    for(int i = x-1, j = y-1 ; i >= 0 and j >= 0 ; i--, j--)
    {
        if(b[i][j])
            return false ; 
    }
    
    for(int i = x+1, j = y-1 ; i < n and j >= 0 ; i++, j--)
    {
        if(b[i][j])
            return false ;
    }
    
    for(int i = x-1, j = y+1 ; i >= 0 and j < n ; i--, j++)
    {
        if(b[i][j])
            return false ; 
    }
    
    return true ; 
}

bool fill_queen(vector<vector<int> > & b, int queen)
{
    if(queen == n)
        return true ; 
        
    for(int i = 0 ; i < n ; i++)
    {
        if(row[i] == 0)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(col[j] == 0 and chech_dia(b, i, j))
                {
                    b[i][j] = 1 ; 
                    row[i] = 1 ; 
                    col[j] = 1 ; 
                    
                    if(fill_queen(b, queen+1))
                        return true ; 
                        
                    b[i][j] = 0 ; 
                    row[i] =  0 ;
                    col[j] = 0 ; 
                }
            }
        }
    }
    
    return false ; 
}


int main()
{
    cin >> n ; 
    
    vector<vector<int> > b(n, vector<int>(n, 0)); 
    
    row = vector<bool>(n, 0); 
    col = vector<bool>(n, 0);
    /*dia_1 = vector<bool>(n, 0);
    dia_2 = vector<bool>(n, 0);*/
    
    int queen = 0 ; 
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin >> b[i][j] ; 
                
            if(b[i][j])
            {
                queen++ ; 
                row[i] = 1 ;
                col[j] = 1 ;
            }
        }
    }
    
    fill_queen(b, queen); 
    
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cout << b[i][j] << " " ; 
        }
        cout << endl ; 
    }

}