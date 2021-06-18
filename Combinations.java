import java.util.*;
public class Hello {
    
    static int res = 0 ; 
    
    public static boolean sumZero(ArrayList<Integer> list)
    {
        if(list.size() == 0)
            return false ;
            
        int sum = 0 ; 
        
        for(Integer l : list)
            sum += l ;
        
        return (sum == 0) ; 
        
    }
    
    public static void combination(int arr[], ArrayList<Integer> list, int i)
    {
        if(sumZero(list))
            res++ ; 
        
        for(int j = i ; j < arr.length ; j++)
        {
            list.add(arr[j]); 
            combination(arr, list, j+1); 
            list.remove(list.size()-1);
        }
    }
    
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); 
        int arr[] = new int[n] ;
        
        for(int i = 0 ; i < n ; i++)
            arr[i] = sc.nextInt();
            
        ArrayList<Integer> list = new ArrayList<Integer>() ;
        combination(arr, list, 0);
            
        System.out.println(res);
        
    }
}