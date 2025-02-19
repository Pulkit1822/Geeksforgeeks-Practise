//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq;
        priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>>filled;
        
        vector<int>mp(n,0);
        int ans=0;
        sort(meetings.begin(),meetings.end());
        for(int i=0;i<n;++i){
            pq.push(i);
        }
        for(auto i:meetings){
            int a=i[0];int b=i[1];
            
            while(!filled.empty() && filled.top().first<=a){
                pq.push(filled.top().second);
                filled.pop();
            }
            
            int index;
            if(!pq.empty()){
                index=pq.top();
                pq.pop();
                filled.push({b,index});
            }
            else{
              auto q=filled.top();
              filled.pop();
              index=q.second;
              filled.push({q.first+b-a,index});
            }
            mp[index]++;
    
        }
        for(int i=0;i<n;++i){
            if(mp[ans]<mp[i]){
                ans=i;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends