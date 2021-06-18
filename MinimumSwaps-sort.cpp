#include <bits/stdc++.h>
 
using namespace std;

int main()
{
    int n ; 
    cin >> n ; 
    vector<int> v(n+1); 
    unordered_map<int, int> m ; 
    
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> v[i] ;
        m[v[i]] = i ; 
    }
    
    int minSwaps = 0 ; 
    
    for(int i = 1 ; i <= n ; i++)
    {
        while(v[i] != i)
        {
            swap(v[i], v[v[i]]); 
            minSwaps++ ;
        }
    }
    cout << minSwaps ;
}

// -------------------------- Descending Order ----------------------------------- // 

#include <bits/stdc++.h>
 
using namespace std;

int main()
{
    int n ; 
    cin >> n ; 
    vector<int> v(n+1); 
    unordered_map<int, int> m ; 
    
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> v[i] ; 
        m[v[i]] = i ; 
    }
    
    int minSwap = 0, idx ; 
    for(int i = 1 ; i <= n ; i++)
    {
        while(v[i] != n-i+1)
        {
            idx = m[n-i+1] ;
            m[n-i+1] = i ;
            m[v[i]] = idx ;
            swap(v[i], v[idx]);

            minSwap++ ;
        }
        cout << v[i] ;
    }
    
    cout << minSwap ;
}