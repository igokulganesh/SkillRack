#include <bits/stdc++.h>
 
using namespace std;

typedef vector<vector<int>> v2d ; 

int n ; 

void fill_rooks(v2d & b, vector<int> & row, vector<int> & col, int rooks)
{
    if(rooks == n)
        return ; 
        
    for(int i = 0 ; i < n ; i++)
    {
        if(row[i] == 0)
        {
            row[i] = 1 ; 
            for(int j = 0 ; j < n ; j++)
            {
                if(col[j] == 0)
                {
                    col[j] = 1 ; 
                    b[i][j] = 1 ; 
                    fill_rooks(b, row, col, rooks+1); 
                }
            }
        }
    }
}

int main()
{
    cin >> n ;
    
    v2d b(n, vector<int>(n, 0)) ; 
    vector<int> row(n, 0); 
    vector<int> col(n, 0); 
    int rooks = 0 ; 
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin >> b[i][j] ; 
            
            if(b[i][j])
            {
                rooks++ ; 
                row[i] = 1 ; 
                col[j] = 1 ;  
            }
        }
    }
    
    fill_rooks(b, row, col, rooks) ;
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cout << b[i][j] << " " ; 
        }
        cout << endl ; 
    }
    return 0 ; 
}
