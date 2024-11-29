//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;
import java.util.stream.*;

class GFG {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String s1 = br.readLine(); // first string
            String s2 = br.readLine(); // second string

            Solution obj = new Solution();

            if (obj.areAnagrams(s1, s2)) {
                System.out.println("true");
            } else {
                System.out.println("false");
            }
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    // Function is to check whether two strings are anagram of each other or not.
    public static boolean areAnagrams(String s1, String s2) {
            int freq1[]=new int[26];
            int freq2[]=new int[26];
            if(s1.length() != s2.length())
            {
                return false;
            }
            int j=0;
            for(int i=0;i<(s1.length());i++)
            {
                j=(int)(s1.charAt(i))-97;
                freq1[j]++;
                
                
                j=(int)(s2.charAt(i))-97;
                freq2[j]++;
            }
            
            
            for(int i=0;i<26;i++)
            {
                if(freq1[i]!=freq2[i])
                {
                    return false;
                }
            }
            
            return true;
        // Your code here
    }
}