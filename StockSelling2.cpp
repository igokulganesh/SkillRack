#include <bits/stdc++.h>
 
using namespace std;

int main()
{
    int n ; 
    cin >> n ; 
    
    vector<int> day(n) ; 
    
    for(int i = 0 ; i < n ; i++)
        cin >> day[i] ; 
        
    int profit = 0 ; 
    int tempProfit = 0 ; 
    int stock = day[0] ; 
    
    for(int i = 1 ; i < n ; i++)
    {
        if(stock < day[i] and tempProfit < day[i]-stock)
        {
            tempProfit = day[i]-stock ; 
        }
        else
        {
            stock = day[i] ; 
            profit += tempProfit ;
            tempProfit = 0 ; 
        }
    }
    
    cout << profit+tempProfit ; 
}