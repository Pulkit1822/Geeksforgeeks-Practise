//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
/*You are required to complete this method*/
    bool solve(string &s , string &p , int i , int j , vector<vector<int>> &dp ){
        if(i < 0 && j < 0 ) return true ;
        if(i >= 0 && j < 0  ) return false ;
        if(i < 0 && j >= 0 ){
            for(int k = 0 ; k <= j ; k++ ){
                if(p[k] != '*') return false ;
            }
            return true ;
        }
        if(dp[i][j] != -1 ) return dp[i][j] ;
        
        
        if(s[i] == p[j] || p[j] == '?'  ) return dp[i][j] = solve(s , p , i-1 , j-1 , dp );
        
        else if(p[j] == '*' ) return dp[i][j] = solve(s , p , i - 1 , j , dp ) || solve(s , p , i , j - 1 , dp ); 
        
        else return dp[i][j] = false ;
    }
    int wildCard(string p ,string s){
        int n = s.size() ;
        int m = p.size() ;
        vector<vector<int>> dp(n + 1 , vector<int>(m + 1, -1 ));
        return solve(s , p , n - 1 , m - 1 , dp );
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends