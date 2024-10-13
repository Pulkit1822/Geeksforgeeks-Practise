//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            String S = in.readLine();
            
            Solution ob = new Solution();
            System.out.println(ob.maxLength(S));
        }
    }
}
// } Driver Code Ends


//User function Template for Java
class Solution{
    static int maxLength(String s){
        // code here
      Stack<Integer> stack = new Stack<>();
      stack.push(-1);       // at first push -1 to stack
      int max=0;            //take max variable = 0 initially
      for(int i=0;i<s.length();i++){
      Character ch = s.charAt(i);
        if(ch == '('){
            stack.push(i);
        }
        else{
            stack.pop();
            if(stack.isEmpty()){
                stack.push(i);
            }
            max = Math.max(max,i-stack.peek());
        }
      }
    return max;
    
    }
}

