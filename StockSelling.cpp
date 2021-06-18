#include <bits/stdc++.h>
 
using namespace std;

int main()
{
    int n ; 
    cin >> n ; 
    vector<int> v(n) ; 
    
    for(int i = 0 ; i < n ; i++)
        cin >> v[i] ; 
        
    
    int profit = 0 ;
    int stock = v[0] ; 
    for(int i = 1 ; i < n ; i++)
    {
        if(stock < v[i])
        {
            profit = max(profit, v[i] - stock);
        }
        else
        {
            stock = v[i] ; 
        }
    }
    cout << profit ; 
}