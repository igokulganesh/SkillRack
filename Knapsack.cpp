#include <bits/stdc++.h>
 
using namespace std;

/*struct Item
{
    int w, p ; 
};

vector<vector<int>> dp ; 

int knapsack(vector<Item> & v, int weight, int i)
{
    if(v.size() == i)
        return 0 ; 
    
    if(dp[weight][i] == 0)   
    {
        if(weight < v[i].w)
            dp[weight][i] = knapsack(v, weight, i+1); 
        else
            dp[weight][i] = max( v[i].p + knapsack(v, weight-v[i].w, i+1), knapsack(v, weight, i+1)); 
    }
    
    return dp[weight][i] ; 
}

int main()
{
    int weight, n ;
    cin >> weight >> n ;
    
    vector<Item> v(n);
    
    for(int i = 0 ; i < n ; i++)
        cin >> v[i].w >> v[i].p ;
        
    dp = vector<vector<int>>(weight+1, vector<int>(n));
    
    cout << knapsack(v, weight, 0);
    
    //cout << dp.back()[0] ; 
}*/

int main()
{
    int weight, n ;
    cin >> weight >> n ;
    
    vector<int> w(n);
    vector<int> p(n);
    
    for(int i = 0 ; i < n ; i++)
        cin >> w[i] >> p[i] ;
        
    vector<vector<int>> dp(weight+1, vector<int>(n+1, 0));

    for(int i = 1 ; i <= weight ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            if(w[j-1] > i)
            {
                dp[i][j] = dp[i][j-1] ;  
            }
            else
            {
                dp[i][j] = max(dp[i][j-1], (p[j-1] + dp[i-w[j-1]][j-1]));
            }
        }
    }

    cout << dp[weight][n] ; 
}