//{ Driver Code Starts
//Initial Template for Java



import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());
        while (tc-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] arr = new int[n];
            String[] inputLine = br.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }

            System.out.println(new Solution().sumBitDifferences(arr, n));
        }
    }
}

// } Driver Code Ends
class Solution {
    long sumBitDifferences(int[] a, int n) {
        long ans=0;
        for(int i=0;i<31;i++)
        {
            long z=0,o=0;
            for(int j=0;j<n;j++)
            {
                if((a[j]>>i)%2==1)
                o++;
                else
                z++;
            }
            ans=ans+2*(z*o);
        }
        return ans;
    }
}