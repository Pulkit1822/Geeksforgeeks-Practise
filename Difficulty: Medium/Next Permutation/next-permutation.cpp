//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        //optimal approach 
        int index = -1;
        int n = arr.size();

        for(int i  = n-2; i>=0; i--)  // step 1 to find longer prefix match
        {                              //n-2 bcz 1 element we have to leave from last to look for next permutation
            if(arr[i] < arr[i+1])       //our task is to figure out breakpoint where we observe the dip
            {
                index  = i;   // we gonna store that index
                break;   // and our 1st step is done
            }
        }

        if(index == -1)  // in case there is no dip, then we're at last permutation of that number and so our ans will be the 1st permutation
        {
            reverse(arr.begin(),arr.end()); // that can be obtained just by reversing the number
            return arr;
        }

        for(int i = n-1; i>index; i--)  // after step 1, step 2 will be find someone greater that arr[index] but the smallest one which is closest to our i/p array
        {
            if(arr[i] > arr[index])   // in case we find it
            {
                swap(arr[i],arr[index]); // we just swap the values
                break;   // and our step 2 is over
            }
        }
        reverse(arr.begin() + index +1,arr.end());  // now we just have to place the remaining in sorted order
                                                       //therefore we just reverse the remaining part
    
        return arr;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends