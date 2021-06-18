#include <bits/stdc++.h>
 
using namespace std;

int n ; 

bool isHasKsum(vector<int> & v, int k)
{
    int sum = 0 ;
    
    int st = 0 ; 
    for(int i = 0 ; i < v.size() ; i++)
    {
        sum += v[i] ; 
        
        while(sum > k)
            sum -= v[st++] ; 
    
        if(sum == k)
            return true ; 
    }
    
    return false ; 
}

int main()
{
    cin >> n ; 
    vector<int> v(n); 
    
    for(auto & e : v)
        cin >> e ;
    
    int k ; 
    cin >> k ; 
    
    cout << (isHasKsum(v, k) ? "Yes" : "No");
}