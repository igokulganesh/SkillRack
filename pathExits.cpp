#include <bits/stdc++.h>
 
using namespace std;

int r, c ; 

bool pathExits(vector<vector<int>> &m, int i, int j, int dr, int dc)
{
    if(i == r or j == c or i < 0 or j < 0)
        return false ; 
    
    if(m[i][j] == 0)
        return false ; 
    
    if(dr == i and dc == j)
        return true ; 

    cout << i << " " << j << endl ; 
    
    return  pathExits(m, i+1, j, dr, dc) or
            pathExits(m, i-1, j, dr, dc) or
            pathExits(m, i, j+1, dr, dc) or
            pathExits(m, i, j-1, dr, dc) ; 
}

int main()
{
    cin >> r >> c ; 
    vector<vector<int>> m(r, vector<int>(c));
    
    for(int i = 0 ; i < r ; i++)
        for(int j = 0 ; j < c ; j++)
            cin >> m[i][j] ; 


            
    int sr, sc, dr, dc; 
    cin >> sr >> sc ; 
    cin >> dr >> dc ; 
    
    for(int i = 0 ; i < r ; i++)
    { 
        for(int j = 0 ; j < c ; j++)
            cout << m[i][j] << " " ;    
        printf("\n");
    }

    cout << sr << " " << sc ; 
    cout << dr << " " << dc << endl ; 

    cout << (pathExits(m, sr, sc, dr, dc) ? "yes" : "no");

}

/*

4 5
1 0 1 1 0
0 1 0 1 1
1 1 0 1 0
1 1 1 1 1
1 1
1 4

*/