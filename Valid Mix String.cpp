/*
    Problem Statement 

    Given 3 string values S1, S2 and S3, 
    find if S3 is a valid mix of the first two string values S1 and S2. 
    The third string value S3 is said to be a mix of the first S1 string and the second S2 string, 
    if it can be formed by interleaving the characters of the first string and 
    the second string in a way that maintains the left to the right order of occurrence of the characters 
    for S1 and S2 each string. The program must print YES if it is a valid mix. 
    Else the program must print NO as the output.
*/


/* This is Greedy Solution but only partial solution */
bool isMix(string & s1, string & s2, string & s3)
{
    int i1 = 0, i2 = 0, i3 = 0 ; 
    
    for(i3 = 0 ; i3 < s3.size() ; i3++)
    {
        if(i1 < s1.size() and s1[i1] == s3[i3])
            i1++ ;
        else if(i2 < s2.size() and s2[i2] == s3[i3])
            i2++ ;
        else 
            return false ; 
    }
    
    return (i3 == s3.size() and i1 == s1.size()-1 and i2 == s2.size()-1) ; 
}

int main()
{
    string s1, s2, s3 ; 

    cin >> s1 ;
    cin >> s2 ; 
    cin >> s3 ;
    
    cout << (isMix(s1, s2, s3) ? "YES" : "NO" )  ;
}


/* Recursion Based solution but still working */
bool isMix(string & s1, string & s2, string & s3, int i1, int i2, int i3)
{
    if(i1 == s1.size() and i2 == s2.size() and i3 == s3.size())
        return true ;
        
    if(i1 < s1.size() and i2 < s2.size() and s1[i1] == s2[i2] and s3[i3] == s1[i1])
    {
        return (isMix(s1, s2, s3, i1+1, i2, i3+1) or isMix(s1, s2, s3, i1, i2+1, i3+1)) ;
    }

    if(i1 < s1.size() and s1[i1] == s3[i3])
        return isMix(s1, s2, s3, i1+1, i2, i3+1) ; 
        
    if(i2 < s2.size() and s2[i2] == s3[i3])
        return isMix(s1, s2, s3, i1, i2+1, i3+1) ;
        
    return false ;   
}

bool isMix(string & s1, string & s2, string & s3)
{
    if(s1.size() + s2.size() != s3.size())
        return false ; 
    
    return isMix(s1, s2, s3, 0, 0, 0); 
}

int main()
{
    string s1, s2, s3 ; 

    cin >> s1 ;
    cin >> s2 ; 
    cin >> s3 ;
    
    cout << (isMix(s1, s2, s3) ? "YES" : "NO" )  ;
}