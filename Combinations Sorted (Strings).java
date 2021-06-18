import java.util.*;
public class Hello {
    
    static ArrayList<String> res = new ArrayList<String>();
    
    public static void PrintList(ArrayList<Character> list)
    {
        if(list.size() == 0)
            return ; 
            
        String s = "" ; 
        for(Character c : list)
            s += c ;
            
        res.add(s);  
    }
    
    public static void combination(char arr[], ArrayList<Character> list, int i)
    {
        PrintList(list); 
        
        for(int j = i ; j < arr.length ; j++)
        {
            list.add(arr[j]); 
            combination(arr, list, j+1); 
            list.remove(list.size()-1); 
        }
    }

    public static void main(String []args) 
    {   
        Scanner sc = new Scanner(System.in); 
        String s = sc.nextLine(); 
        
        char arr[] = s.toCharArray(); 
        
        ArrayList<Character> list = new ArrayList<Character>() ;
        
        combination(arr, list, 0);
        
        Collections.sort(res); 

        for(String r : res)
            System.out.println(r);
        
    }
}