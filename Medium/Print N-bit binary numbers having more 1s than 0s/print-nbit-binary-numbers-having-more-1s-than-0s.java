//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(read.readLine());
            Solution ob = new Solution();
            ArrayList<String> result = ob.NBitBinary(n);
            for(String value  : result){
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }
}
// } Driver Code Ends





//User function Template for Java

class Solution {
    ArrayList<String> NBitBinary(int N) {
        // code here
        ArrayList<String> li = new ArrayList<>();
        getAllBits(N,0,0,"",li);
        return li;
    }
    public void getAllBits(int n,int countZ,int countO,String bit,ArrayList<String> li){
        if(n==0){
            li.add(bit);
            return;
        }
        getAllBits(n-1,countZ,countO+1,bit+"1",li);
        if(countZ<countO)
            getAllBits(n-1,countZ+1,countO,bit+"0",li);
    }
}