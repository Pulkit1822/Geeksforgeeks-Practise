//{ Driver Code Starts
import java.io.*;
import java.util.*;


class IntArray
{
    public static int[] input(BufferedReader br, int n) throws IOException
    {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for(int i = 0; i < n; i++)
            a[i] = Integer.parseInt(s[i]);
        
        return a;
    }
    
    public static void print(int[] a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }
    
    public static void print(ArrayList<Integer> a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }
}


class IntMatrix
{
    public static int[][] input(BufferedReader br, int n, int m) throws IOException
    {
        int[][] mat = new int[n][];
        
        for(int i = 0; i < n; i++)
        {
            String[] s = br.readLine().trim().split(" ");
            mat[i] = new int[s.length];
            for(int j = 0; j < s.length; j++)
                mat[i][j] = Integer.parseInt(s[j]);
        }
        
        return mat;
    }
    
    public static void print(int[][] m)
    {
        for(var a : m)
        {
            for(int e : a)
                System.out.print(e + " ");
            System.out.println();
        }
    }
    
    public static void print(ArrayList<ArrayList<Integer>> m)
    {
        for(var a : m)
        {
            for(int e : a)
                System.out.print(e + " ");
            System.out.println();
        }
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            int[] a = IntArray.input(br, 2);
            
            
            int[][] pairs = IntMatrix.input(br, a[1], 2);
            
            Solution obj = new Solution();
            long res = obj.numberOfPairs(a[0], a[1], pairs);
            
            System.out.println(res);
            
        }
    }
}

// } Driver Code Ends

class Solution {
    public static long numberOfPairs(int N, int P, int[][] pairs) {
        int par[] = new int[N];
        int rank[] = new int[N];

        for (int i = 0; i < N; i++)
            par[i] = i;

        for (int i = 0; i < pairs.length; i++) {
            int s = pairs[i][0];
            int e = pairs[i][1];

            int x = find(par, s);
            int y = find(par, e);

            if (x != y)
                union(par, rank, x, y);
        }

        long res = 0;

        int dp[] = new int[N];

        for (int i = 0; i < N; i++)
            dp[find(par, i)]++;

        int rem = N;
        for (int i = 0; i < N; i++) {
            res += dp[i] * (rem - dp[i]);
            rem -= dp[i];
        }

        return res;
    }

    public static void union(int par[], int rank[], int x, int y) {
        if (rank[x] < rank[y]) {
            par[x] = y;
        } else if (rank[y] < rank[x]) {
            par[y] = x;
        } else {
            par[y] = x;
            rank[x]++;
        }
    }

    public static int find(int par[], int e) {
        if (par[e] == e)
            return e;

        return par[e] = find(par, par[e]);
    }
}
