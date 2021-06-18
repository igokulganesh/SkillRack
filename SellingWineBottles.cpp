#include <bits/stdc++.h>
 
using namespace std;	

int maxRevenue(vector<int> & v, int l, int  r, int yr, vector<vector<int>> & dp) // left , right and year
{
    if(dp[l][r])
        return dp[l][r] ; 
        
    if(l == r)
        return v[l] * yr ;
        
    int res1 = v[l] * yr + maxRevenue(v, l+1, r, yr+1, dp) ; 
    int res2 = v[r] * yr + maxRevenue(v, l, r-1, yr+1, dp) ; 
    dp[l][r] = max(res1, res2); 
    
    return dp[l][r] ; 
}

int main()
{
    int n ; 
    cin >> n ; 
    vector<int> v(n);
    
    vector<vector<int> > dp(n, vector<int>(n,0)); 
    
    for(int i = 0 ; i < n ; i++)
        cin >> v[i]; 
        
    cout << maxRevenue(v, 0, n-1, 1, dp);
}