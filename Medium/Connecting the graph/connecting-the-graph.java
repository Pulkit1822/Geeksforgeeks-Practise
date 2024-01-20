//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[][] edge = new int[m][2];
            for (int i = 0; i < m; i++) {
                edge[i][0] = sc.nextInt();
                edge[i][1] = sc.nextInt();
            }

            Solution obj = new Solution();
            int ans = obj.Solve(n, edge);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends
class DisjointSet{
    List<Integer> rank;
    List<Integer> parent;
    
    DisjointSet(int V){
        rank = new ArrayList<Integer>();
        parent = new ArrayList<Integer>();
        
        for(int i=0;i<V;i++){
            rank.add(0);
            parent.add(i);
        }
    }
    
    void unionByRank(int u, int v){
        int pu = findUParent(u);
        int pv = findUParent(v);
        
        if(pu == pv) return;
        
        if(rank.get(pu) == rank.get(pv)){
            parent.set(pu,pv);
            rank.set(pv,rank.get(pv)+1);
        } else if(rank.get(pu) < rank.get(pv)){
            parent.set(pu,pv);
        }
        else {
            parent.set(pv,pu);
        }
    }
    
    int findUParent(int node){
        if(parent.get(node) == node){
            return node;
        }
        else{
            parent.set(node,findUParent(parent.get(node)));
            return parent.get(node);
        }
    }
    
    
    boolean hasSameUParent(int u,int v){
        return findUParent(u) == findUParent(v);
    }
}

class Solution {

    public int Solve(int n, int[][] edge) {
        int extra_edges = 0;
        DisjointSet dj = new DisjointSet(n);
        
        for(int i=0;i<edge.length;i++){
            if(!dj.hasSameUParent(edge[i][0],edge[i][1])){
                dj.unionByRank(edge[i][0],edge[i][1]);    
            } else {
                extra_edges++;
            }
            
        }
            
        int num_conn = 0;
        for(int i=0;i<dj.parent.size();i++){
            if(dj.parent.get(i) == i){
                num_conn++;
            }
        }
        
        return extra_edges >= num_conn-1 ? num_conn-1 : -1;
    }
}