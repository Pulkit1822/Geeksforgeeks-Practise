//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array           // is approach ka yhi fayda he ki hum phle he check kr lete he ki curr ele ke ag peeche wala element exist krta he to hi hum peeche ja jakr starting point tk jate he or waha se uski streak count krte, or agr nhi hota pichle wala to us iteration ki streak count krte he nhi
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
                                      //optimal solution
        if(N == 0) return 0;        
        int longest = 1;
        unordered_set<int> st;     // declare unordered set

        for(int i = 0; i<N; i++)   // step 1:- insert arr values into set to remove duplicates
        {
            st.insert(arr[i]);
        }
        //Find the longest sequence:
        for(auto it: st)
        {
            //if 'it' is a starting number:          //step:- 2
            if(st.find(it-1) == st.end())         //agr koi set me current value se 1 km value he set ke andr, to hum age ke elements gin na shuru krenge wrna nhi 
            {
                int cnt = 1;   // cnt 1 se krenge
                int x = it;           
                while(st.find(x+1) != st.end())  //step:- 3 agr current ele ke age wala is array ki end tk mila to
                {
                    x++;      // x ki value bda denge take ab uske agle wala dhund paye
                    cnt++;     //or streak bhi bada denge
                }
                longest = max(longest, cnt);     //step:- 4 hr baar jitti bhi streak bnegi usme se max value le lenge
            }
        }
        return longest;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends