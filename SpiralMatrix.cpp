#include <bits/stdc++.h>
 
using namespace std;

int main()
{
    int row, col ; 
    cin >> row >> col ; 
    vector<vector<int>> v(row, vector<int>(col));
    for(int i = 0 ; i < row ; i++)
        for(int j = 0 ; j < col ; j++)
            cin >> v[i][j] ; 
            
    vector<vector<bool>> isVisited(row, vector<bool>(col, false)); 
        
    int dr[] = {0, 1,  0, -1 };
    int dc[] = {1, 0, -1,  0 }; 
    
    int di = 0, r = 0, c = 0 ; 
    for(int i = 0 ; i < row * col ; i++)
    {
        cout << v[r][c] << " " ; 
        isVisited[r][c] = true ; 
            
        r += dr[di] ; 
        c += dc[di] ; 
        
        if(r < 0 or r == row or c < 0 or c == col or isVisited[r][c])
        {
            r -= dr[di] ; 
            c -= dc[di] ; 
            di = (di+1)%4 ;
            r += dr[di] ; 
            c += dc[di] ; 
        }
    }
}