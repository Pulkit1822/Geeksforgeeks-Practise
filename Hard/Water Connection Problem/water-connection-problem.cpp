//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        vector<int>in(n+5,-1),out(n+5,-1),dia(n+5,-1);
        for(int i=0;i<p;i++){
            out[a[i]]=b[i];
            in[b[i]]++;
            dia[a[i]]=d[i];
        }
        int t=0;
        for(int i=1;i<=n;i++)t+=in[i]==-1;
        vector<vector<int>>ans;
        for(int i=1;i<=n;i++){
            if(in[i]!=-1)continue;
            if(out[i]==-1)continue;
            int st=i,end=i,mi=INT_MAX;
            while(out[st]!=-1)mi=min(mi,dia[st]),end=st,st=out[st];
            ans.push_back({i,st,mi});
        }
        sort(begin(ans),end(ans));
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends