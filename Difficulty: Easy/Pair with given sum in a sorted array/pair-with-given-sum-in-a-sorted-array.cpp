//{ Driver Code Starts
#include <bits/stdc++.h>


using namespace std;




// } Driver Code Ends

class Solution{
  public:
    int Countpair(int arr[], int n, int sum){
        
        // Complete the function
         int count = 0;
        for(int i = 0; i<n; i++)          // 1 ko fix kro or baki se compare kro
        {
            for(int j = i+1; j<n; j++)       //pr bar bar mt kro, jaise eg 1 me
            {                                //2,7 1st iteration me ho chuke honge compare
                if(arr[i] + arr[j] == sum)     //isliiye dusri bar 7,2 compare krna ka matlab nhi he
                {                                    //islye 2nd loop j = i+1 se start ho rha he
                    count++;      // finally return the index whose pair sum == target
                }
            }
        }
        if(count == 0)
        {
            return -1;
        }
        return count;
    
        
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        int arr[n+1];
        
        for(int i=0;i<n;i++)
        cin>>arr[i];

        int sum;
        cin>>sum;
        Solution obj;
        cout << obj.Countpair(arr, n, sum) << endl;
        
    }
	return 0;
}

// } Driver Code Ends