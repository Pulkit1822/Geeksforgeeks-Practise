//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        vector<int> pat_map(256,0);
        int unique_char = 0;
        
        int len_p = p.length();
        int len_s = s.length();
        for(int i = 0 ; i < len_p ; ++i){
            int index = (int)p[i];
            if(pat_map[index] == 0) unique_char++;
            pat_map[index]++;
        }
        
        int start = 0;
        int curr  = 0;
        int ans_start = 0;
        int ans_len   = INT_MAX;
        
        vector<int> hay_map(256,0);
        int match_count = 0;
        while(curr < len_s){
            int index = (int)s[curr];
            hay_map[index]++;
            
            if(hay_map[index] == pat_map[index]) match_count++;
            if(match_count == unique_char){
                //cout<<"Start checking from : "<<start<<" to "<<curr<<endl;
                while(match_count == unique_char){
                    int window_len = curr - start + 1;
                    if(ans_len > window_len){ans_len = window_len; ans_start = start;}
                    
                    int index = (int)s[start];
                    hay_map[index]--;
                    if(hay_map[index] < pat_map[index]) match_count--;
                    start++;
                }
            }
            curr++;
        }
        
        if(ans_len == INT_MAX) return "-1";
        return s.substr(ans_start,ans_len);
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends