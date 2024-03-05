//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;
class GfG
{
    public static void main (String[] args)
    {
        
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int l = sc.nextInt();
            int n = sc.nextInt();
            
            int arr[] =  new int[l];
            
            for(int i = 0;i<l;i++)
                arr[i] = sc.nextInt();
            
            Solution ob = new Solution();
                
            if(ob.findPair(arr, l, n)==true)
                System.out.println(1);
                
            else
                System.out.println(-1);    
                
        }
        
    }
}
// } Driver Code Ends
class Solution
{
    public boolean findPair(int arr[], int size, int n)
    {
        
       HashMap<Integer,Integer> hm = new HashMap<>();
       
       for(int i=0;i<arr.length;i++){
           hm.put(arr[i],hm.getOrDefault(arr[i],0)+1);
       }
       if(n==0){
            for(int i=0;i<arr.length;i++){
                if(hm.get(arr[i])>=2){
                    return true;
                }
            }
       }
        else{
       for(int i=0;i<arr.length;i++){
           int com = n + arr[i];
           if(hm.containsKey(com)  ){
               return true;
           }
       }
        }
        return false;
    }
}