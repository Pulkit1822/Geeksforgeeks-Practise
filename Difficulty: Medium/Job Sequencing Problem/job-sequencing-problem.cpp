//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/


class Solution 
{
    public:
    bool static cmp(Job a,Job b){
    return (a.profit>b.profit);
   
        
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int prof=0;
        int jc=0;
        sort(arr,arr+n,cmp);
        int maxd=0;
        for(int i=0;i<n;i++){
            maxd=max(maxd,arr[i].dead);
        }
        int tim[maxd]={0};
       for(int i=0;i<n;i++){
           int j=arr[i].dead-1;
           while(j>=0&&tim[j]!=0 ){
               j--;
           }
           if(j>=0){tim[j]=arr[i].id;
               jc++;
               prof+=arr[i].profit;
           }
       }
       
   
       
       
       vector<int> v;
       v.push_back(jc);
v.push_back(prof);

        return v;
    } 
};


//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends