//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
     static bool comp(pair<int,int>&p1,pair<int,int>&p2){
        if(p1.first>p2.first){
            return true;
        }
        else if(p1.first==p2.first&&p1.second<p2.second){
            return true;
        }
        return false;
    }
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        map<int,int>mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        vector<pair<int,int>>ans;
        for(auto x:mp){
            ans.push_back({x.second,x.first});
        }
        sort(ans.begin(),ans.end(),comp);
        // reverse(ans.begin(),ans.end());
        vector<int>val;
        for(int i=0;i<ans.size();i++){
            int p=ans[i].first;
            while(p>0){
                val.push_back(ans[i].second);
                p--;
            }
        }
        return val;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends