//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
    {
        int n = s.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int maxiCnt = 0;
        int miniCnt = 0;
        set<int>set;
        
        if(n == 1 || n == 2 || n == 3)
        {
            return 1;
        }
        
        unordered_map<char , int>mp;
        
        for(int i=0; i<n; i++)
        {
            mp[s[i]]++;
            
            if(mp[s[i]] > maxi)
            {
                maxi = mp[s[i]];
            }
        }
        
        for(auto i : mp)
        {
            if(i.second < mini)
            {
                mini = i.second;
            }
        }
        
        for(auto i:mp)
        {
            set.insert(i.second);
            
            if(i.second == maxi)
            {
                maxiCnt++;
            }
            
            if(i.second == mini)
            {
                miniCnt++;
            }
        }
        
        if(mp.size() == 1)
        {
            return 1;
        }
        
        if(miniCnt == mp.size()-1 && maxi == mini+1)
        {
            return 1;
        }
        
        if(maxiCnt == mp.size()-1 && mini == 1)
        {
            return 1;
        }
        
        if(set.size() == 1)
        {
            return 1;
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends