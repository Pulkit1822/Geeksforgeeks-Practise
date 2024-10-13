//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function.  //better solution using hashing
        map<int, int> preSumMap;   // works for both 0,negatives and positives(both k and value inside elements)
        int sum = 0;  
        int maxLen = 0;
        for(int i = 0; i<N; i++)
        {
            sum += A[i];
            if(sum == K)
            {
                maxLen = max(maxLen, i+1);  // jis index pe sum, 'k' ke brabar aya usse 1 jyada hoga kyuki indexing 0 se he
            }
            int rem = sum - K;
            if(preSumMap.find(rem) != preSumMap.end())
            {
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }
            if(preSumMap.find(sum) == preSumMap.end())
            {
                preSumMap[sum] = i;
            }
        }
        return maxLen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends