//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // your code here
        int m=1e9+7;
        long long int mf = 1;
        long long sum=0;
        for (int i=s.size()-1; i>=0; i--)
        {
            sum =(sum+ ((s[i]-'0')*(i+1)*mf)%m)%m;
            mf = (mf*10 + 1)%m;
        }
        return sum;

    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends