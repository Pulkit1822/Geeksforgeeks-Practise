//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends


class Solution {
  public:
    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        vector<vector<int>> ans;
        vector<int> v;
        map<int,int> m;
        set<pair<int,int>> s;
        for(int i=0;i<N;i++){
            if(m[arr[i]]>0) s.erase({-m[arr[i]],arr[i]});
            m[arr[i]]++;
            s.insert({-m[arr[i]],arr[i]});
            int p=K;
            for(auto i:s) { 
                if(p==0) break;
                v.push_back(i.second);
                p--;
        }
        ans.push_back(v);
        v.clear();
    }
    return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> a(N);
        Array::input(a,N);
        
        Solution obj;
        vector<vector<int>> res = obj.kTop(a, N, K);
        
        for(auto it:res)
            Array::print(it);
        
    }
}

// } Driver Code Ends