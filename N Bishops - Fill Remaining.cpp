/*
In a N*N square chessboard, certain number of bishops are placed. 
The program must accept the positions of B bishops(marked by 1). 
The empty squares are marked by the value 0. The program must fill in the remaining N-B bishops 
with the condition that only one bishop must be in a row and one bishop must be in a column 
so that the bishops do not attack each other. The program must finally print the 
arrangement of the bishops in the chessboard (if multiple arrangements are possible print the possibility 
which occurs with the left most column filled starting from the top row). If such an arrangement is not possible, 
then the program must print NotPossible as the output.

Note: In Chess, a bishop can move diagonally. 
The movement can happen till the end of the board is reached or another piece (like Rook, Knight, Bishop, Pawn etc is encountered). 
But in this program only the N bishops are placed and no other pieces will be present on the board.

*/

int n ; 

bool isValid(vector<vector<int> > & b, int x, int y)
{
    for(int i = x+1, j = y+1 ; i < n and j < n ; i++, j++)
        if(b[i][j])
            return false ; 
    
    for(int i = x-1, j = y-1 ; i >= 0 and j >= 0 ; i--, j--)
        if(b[i][j])
            return false ; 
    
    for(int i = x+1, j = y-1 ; i < n and j >= 0 ; i++, j--)
        if(b[i][j])
            return false ; 
            
        
    for(int i = x-1, j = y+1 ; i >= 0 and j < n ; i--, j++)
        if(b[i][j])
            return false ; 
     return true ;
}

bool isValid(vector<vector<int> > & b)
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(b[i][j] and isValid(b, i, j) == false)
                return false ;
        }
    }
    return true ;
}

bool fill_bishops(vector<vector<int>> & b, vector<int> & row, int bishop)
{
    if(bishop == n)
        if(isValid(b))
            return true ; 
        else 
            return false ; 
        
    for(int i = 0 ; i < n ; i++)
    {
        if(row[i] == 0)
        {
            row[i] = 1 ; 
            for(int j = 0 ; j < n ; j++)
            {
                b[i][j] = 1 ; 
                if(isValid(b, i, j))
                {
                    if(fill_bishops(b, row, bishop+1))
                        return true ;
                }
                b[i][j] = 0 ; 
            }
            row[i] = 0 ; 
        }
    }
    
    return false ; 
}

int main()
{
    cin >> n ; 
    
    vector<vector<int> > b(n, vector<int>(n, 0)) ; 
    vector<int> row(n, 0); 
    int bishop = 0 ; 
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin >> b[i][j] ;
            
            if(b[i][j])
            {
                row[i] = 1 ; 
                bishop++ ; 
            }
        }
    }        
    
    if(fill_bishops(v, row, bishop))
    {
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
                cout << b[i][j] << " " ; 
            cout << endl ; 
        }
    }
    else
        cout << "NotPossible" ; 
        
    return 0 ; 
}

