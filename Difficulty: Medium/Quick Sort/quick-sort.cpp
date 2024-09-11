//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends


class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low < high){
            int partitionIndex = partition(arr, low, high);
            quickSort(arr, low, partitionIndex-1);
            quickSort(arr, partitionIndex+1, high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        int pivot = arr[low]; // Pivot is the first element
        int i = low;          // Start pointer
        int j = high;         // End pointer

        while(i < j){
            while (arr[i] <= pivot && i <= high-1) // Find the first element greater than pivot
            {
                i++;
            }
            while (arr[j] > pivot && j >= low+1) // Find the first element less than or equal to pivot
            {
                j--;
            }
            if (i < j) // Swap elements that are out of place
            {
                swap(arr[i], arr[j]);
            }
        }
        // Swap pivot element to its correct position
        swap(arr[low], arr[j]);
        return j;
    }
};



//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends