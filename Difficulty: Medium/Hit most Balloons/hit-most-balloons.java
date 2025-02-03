//{ Driver Code Starts
// Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t =
            Integer.parseInt(br.readLine().trim()); // Inputting the testcases
        while (t-- > 0) {

            int N = Integer.parseInt(br.readLine().trim());

            int arr[][] = new int[(int)(N)][2];

            for (int j = 0; j < 2; j++) {
                String inputLine2[] = br.readLine().trim().split(" ");
                for (int i = 0; i < N; i++) {
                    arr[i][j] = Integer.parseInt(inputLine2[i]);
                }
            }
            Solution ob = new Solution();
            System.out.println(ob.mostBalloons(N, arr));
        
System.out.println("~");
}
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    public int getGCD(int a, int b) {
        if(b==0)
            return a;
        else return getGCD(b,a%b);
    }
    
    public int mostBalloons(int N, int arr[][]) {

        if (N <= 2) {
            return N;
        }
        int maxBalloons = 2;

        for (int i = 0; i < N; i++) {
            int identical = 0;
            Map<String, Integer> slope = new HashMap<>();

            for (int j = 0; j < N; j++) {

                if (i != j) {
                    if (arr[i][0] == arr[j][0] && arr[i][1] == arr[j][1]) {
                        identical++;
                        
                    } else {
                        int ydiff = arr[i][1] - arr[j][1];
                        int xdiff = arr[i][0] - arr[j][0];
                        int gcd = getGCD(xdiff, ydiff);
                        ydiff /= gcd;
                        xdiff /= gcd;

                        String g = xdiff+"-"+ydiff;
                        if (slope.containsKey(g)) {
                            int value = slope.get(g);
                            value++;
                            slope.put(g, value);

                        } else {
                            slope.put(g, 1);
                        }
                    }
                }
            }
            
            int mostPointsOnSameLine = 1;
            for (Map.Entry<String, Integer> item : slope.entrySet()) {
                mostPointsOnSameLine =
                    Math.max(mostPointsOnSameLine, item.getValue());
            }
            maxBalloons =
                Math.max(maxBalloons, 1 + identical + mostPointsOnSameLine);
        }

        return maxBalloons;
    }
}