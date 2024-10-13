//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findIndex(vector<int>& arr, int key) {
        // code here.
                
        
        int x = - 1 ;
        
        int y = -1 ;
        int n = arr.size();
        
        for(int i = 0 ; i < n ; i++){
        
        if(arr[i] == key) {
        
        x = i ;
        
        break ; }
        
        }
        
         
        
        for(int i = n-1 ;  i >=0 ; i-- ){
        
        if(arr[i] == key){
        
        y = i ;
        
        break ;
        
        }
        
        }
        
        return {x,y};
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> res;
        vector<int> arr;
        string s;
        getline(cin, s);
        stringstream ss(s);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int key;
        cin >> key;
        cin.ignore();
        Solution ob;
        res = ob.findIndex(arr, key);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends