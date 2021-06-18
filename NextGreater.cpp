#include <bits/stdc++.h>
 
using namespace std;

int nextMax(vector<int> & v, int x)
{
    for(int i = x+1 ; i < v.size() ; i++)
    {
        if(v[i] > v[x])
            return i ; 
    }
    
    return x ; 
}

int main(int argc, char** argv)
{
    int n ; 
    cin >> n ; 
    vector<int> v(n); 
    
    for(int i = 0 ; i < n ; i++)
        cin >> v[i] ; 
    
    int mi = 0 ; 
    
    for(int i = 0 ; i < n ; i++)
    {
        if(mi <= i or v[mi] < v[i])
        {
            mi = nextMax(v, i); 
        }
        
        cout << v[mi] << " " ; 
    }
}

#include <bits/stdc++.h>
 
using namespace std; 

int main()
{
    int n ; 
    cin >> n ; 
    vector<int> v(n); 
    vector<int> s ; 
    
    for(int i = 0 ; i < n ; i++)
        cin >> v[i] ; 
    
    s.push_back(v[0]) ; 
    
    for(int i = 1 ; i < n ; i++)
    {
        while(s.size() and s.back() < v[i] )
            s.pop_back(); 
            
        s.push_back(v[i]) ; 
        
        cout << v.back() << " " ; 
    }
}

#include <bits/stdc++.h>
 
using namespace std; 

int main()
{
    int n ; 
    cin >> n ; 
    vector<int> v(n); 
    stack<int> s ; 
    
    for(int i = 0 ; i < n ; i++)
        cin >> v[i] ; 
    
    s.push(v.back()); 
    
    int val ; 
    for(int i = n-2 ; i >= 0 ; i--)
    {
        val = s.top();
        if(val < v[i])
            s.push(v[i]) ;
        else
            s.push(val); 
    }

    while(!s.empty())
    {
        cout << s.top() << " " ; 
        s.pop() ;
    }
}

void printNGE(int arr[], int n)
{
    stack<int> s;

    int arr1[n];

    // iterating from n-1 to 0
    for (int i = n - 1; i >= 0; i--)
    {
        /*We will pop till we get the
        greater element on top or stack gets empty*/
        while (!s.empty() && s.top() <= arr[i])
            s.pop();

        /*if stack gots empty means there
        is no element on right which is greater
        than the current element.
        if not empty then the next greater
        element is on top of stack*/
        if (s.empty())
            arr1[i] = -1;       
        else
            arr1[i] = s.top();      

        s.push(arr[i]);
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ---> " << arr1[i] << endl;
}