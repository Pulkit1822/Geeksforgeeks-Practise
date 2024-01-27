//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution{
    map<string, pair<int, string>> dp;
    
  public:
    string matrixChainOrder(int A[], int n) {
        return matrixChainOrderUtil(A, 0, n - 1).second;
    }
    
    pair<int, string> matrixChainOrderUtil(int p[], int l, int r) {
    	// Base case
    	/*
		For [1, 2, 3], base case will hit when l = 0, r = 1 or l = 1, r = 2
		or we can say we are at matrix A or B
    	l = 0 -> A
    	l = 1 -> B
    	so on..
    	*/
        if(l + 1 == r) return {0, "" + string(1, l + 'A')};
        string key = to_string(l) + ";" + to_string(r);
        if(dp.count(key)) return dp[key];
        
        int currMin = INT_MAX;
        string minString;
        for(int k = l + 1; k < r; k++) {
            auto p1 = matrixChainOrderUtil(p, l, k), p2 = matrixChainOrderUtil(p, k, r);
            if(p1.first + p2.first + p[l] * p[k] * p[r] < currMin) {
                currMin = p1.first + p2.first + p[l] * p[k] * p[r];
                // Multiply te 2 strings
                minString = p1.second + p2.second;
            }
        }
        // Enclose them in brackets and return
        return dp[key] = {currMin, "(" + minString + ")"};

    }
};

//{ Driver Code Starts.

int get(int p[],int n)
{
    int m[n][n],ans = 1e9; 
    for (int i = 1; i < n; i++)
        m[i][i] = 0; 
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n-L+1; i++){ 
            m[i][i + L - 1] = INT_MAX; 
            for (int k = i; k <= i + L - 2; k++){ 
                int q = m[i][k] + m[k + 1][i + L - 1] + p[i-1] * p[k] * p[i + L - 1]; 
                if (q < m[i][i + L - 1])
                { 
                    m[i][i + L - 1] = q;
                }
            }
        }
    }
    return m[1][n-1];
}

int find(string s,int p[])
{
    vector<pair<int,int>> arr;
    int ans = 0;
    for(auto t:s)
    {
        if(t=='(')
        {
            arr.push_back({-1,-1});
        }
        else if(t==')')
        {
            pair<int,int> b=arr.back();
            arr.pop_back();
            pair<int,int> a=arr.back();
            arr.pop_back();
            arr.pop_back();
            arr.push_back({a.first,b.second});
            ans += a.first*a.second*b.second;
        }
        else 
        {
            arr.push_back({p[int(t-'A')],p[int(t-'A')+1]});
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
        {
            cin>>p[i];
        }
        Solution ob;
        string result = ob.matrixChainOrder(p, n);
        if(find(result,p)==get(p,n))
        {
            cout<<"True"<<endl;
        }
        else
        {
            cout<<"False"<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends