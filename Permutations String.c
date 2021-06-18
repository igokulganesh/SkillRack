#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char *s, int l, int h)
{
    char c = s[l] ; 
    s[l] = s[h] ; 
    s[h] = c ; 
}

void permutations(char *s, int l, int h)
{
    if(l == h)
    {
        printf("%s\n", s);
        return ; 
    }
    
    for(int i = l ; i <= h ; i++)
    {
        swap(s, i, l);
        permutations(s, l+1, h); 
        swap(s, i, l); 
    }
}

int main()
{
    char s[15] ; 
    
    scanf("%s", s); 

    int n = strlen(s); 
    
    permutations(s, 0, n-1); 
    
}