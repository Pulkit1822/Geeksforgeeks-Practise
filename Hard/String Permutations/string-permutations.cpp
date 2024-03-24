//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    void solve(string s,multiset<string> &ans,int index,int n){
        
        if(index>=n){
            ans.insert(s);
            return;
        }
        for(int i=index;i<n;i++){
            swap(s[index],s[i]);
            solve(s,ans,index+1,n);
        }
    }
    
    vector<string> permutation(string s)
    {
        multiset<string> ans;
        int n=s.size();
        int index=0;
        
        solve(s,ans,index,n);
        
        vector<string> vc(ans.begin(),ans.end());
        return vc;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends