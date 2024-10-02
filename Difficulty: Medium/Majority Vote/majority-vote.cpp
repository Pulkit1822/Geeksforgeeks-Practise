//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
          int n = nums.size(),k=3;
 
    vector<pair<int, int> > candidates(k - 1);
 
    for (int i = 0; i < k - 1; i++) {
        candidates[i] = { 0, 0 };
    }
 
    for (int num : nums) 
{
        bool found = false;
        for (int j = 0; j < k - 1; j++)
 {
            if (candidates[j].first == num)
           {
                candidates[j].second++;
                found = true;
                break;
            }
        }
        if (!found) 
{
            for (int j = 0; j < k - 1; j++)
 {
                if (candidates[j].second == 0) 
               {
                    candidates[j] = { num, 1 };
                    found = true;
                    break;
                }
            }
        }
 if (!found)
{
            for (int j = 0; j < k - 1; j++) {
                candidates[j].second--;
            }
        }
    }
 
    
    vector<int> ans;
 
    for (int i = 0; i < k - 1; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == candidates[i].first) {
                count++;
            }
        }
 
        if (count > n / k) 
        {
            ans.push_back(candidates[i].first);
        }
        
        
        
        
    }
    if(ans.size()==0)
        ans.push_back(-1);
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends