import java.util.*;
public class Hello {

    static int dif, n, x, res ;
    
    public static void swap(char arr[], int a, int b)
    {
        char temp = arr[a] ;
        arr[a] = arr[b] ;
        arr[b] = temp ; 
    }
    
    public static void checkDif(char arr[])
    {
        int num = Integer.parseInt(new String(arr)); 
        
        if(Math.abs(num-x) < dif)
        {
            dif = Math.abs(num-x); 
            res = num ; 
        }
    }

    public static void permutations(char arr[], int l, int h)
    {
        if(l == h)
        {
            checkDif(arr); 
            return ;
        }
        
        for(int i = l ; i <= h ; i++)
        {
            swap(arr, l, i ); 
            permutations(arr, l+1, h);
            swap(arr, l, i); 
        }
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in); 
        n = sc.nextInt();
        x = sc.nextInt(); 
        dif = Math.abs(n-x); 
        res = n ; 
        
        char c[] = ("" + n).toCharArray();
        
        permutations(c, 0, c.length-1); 
        
        System.out.println(res);    
    }
}