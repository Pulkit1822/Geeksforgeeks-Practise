//{ Driver Code Starts
// C++ program to find union of 
// two sorted arrays 
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{
    public:
    //Function to return a list containing the intersection of two arrays.
    vector<int> printIntersection(int arr1[], int arr2[], int N, int M) 
    { 
        //Your code here
        vector<int> ans;
        int i = 0, j = 0;  // i pointer at arr1 and j at arr2

        while(i < N && j < M)
        {
            if(arr1[i] < arr2[j])
            {
                i++;
            }
            else if(arr2[j] < arr1[i])
            {
                j++;
            }
            else // when both elements are equal
            {
                if(ans.empty() || ans.back() != arr1[i]) // same element dubara nhi ana chahiye ans array me
                {                                        // isliye ans array ke pichle wale element se compare kra rhe he 
                    ans.push_back(arr1[i]);
                }
                i++;
                j++;
            }
        }

        // If no common elements found, return vector with -1
        if(ans.empty())
        {
            ans.push_back(-1);
        }

        return ans;
    }
    

};

//{ Driver Code Starts.
/* Driver program to test above function */
int main() 
{ 
    int T;
    cin >> T;
 
    while(T--){
        
        int N, M;
        cin >> N >> M;
        int arr1[N];
        int arr2[M];
        for(int i = 0;i<N;i++){
            cin >> arr1[i];
        }
        
        for(int i = 0;i<M;i++){
            cin >> arr2[i];
        }
        Solution ob;
        // Function calling 
        vector<int> v;
        v = ob.printIntersection(arr1, arr2, N, M); 
        
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";

        cout << endl;
    }
    
  return 0; 
} 

// } Driver Code Ends