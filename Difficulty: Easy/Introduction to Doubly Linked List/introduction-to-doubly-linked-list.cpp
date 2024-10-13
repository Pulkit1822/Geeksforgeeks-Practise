//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    Node* prev;
    int data;
    Node* next;

    Node() {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value) {
        prev = NULL;
        data = value;
        next = NULL;
    }
};

void printList(Node* node) {
    Node* tmp = node;
    int c1 = 0, c2 = 0;
    if (tmp) {
        while (tmp->next != NULL) {
            c1++;
            tmp = tmp->next;
        }
        while (tmp->prev != NULL) {
            c2++;
            tmp = tmp->prev;
        }
        if (c1 != c2) {
            cout << "-1\n";
            return;
        }
    }
    while (tmp) {
        cout << tmp->data << ' ';
        tmp = tmp->next;
    }
    cout << endl;
}


// } Driver Code Ends
// User function Template for C++

/*
class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};*/

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        // code here
        Node* head = new Node(arr[0]);        // assigning 1st node(head) a value at 0th index of array with its back and next pointer pointing to NULL
        Node* mover = head;                          // not gonna temper the head
        for(int i = 1; i<arr.size(); i++)     // iterating from 1st index till end of array as 0th ele is already assignied a node in DLL
        {
            Node* temp = new Node(arr[i]);   //creating a temp node to assign rest of elements 
            mover->next = temp;         // head ko new node se jodenge(in 1st iteration)
            temp->prev = mover;          // fir us added node ka prev mover ko point krna chahiye
            mover = mover->next;          // or mover ko age bdate jayenge
        } 
        return head;   // finally return the head
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        Node* ans = obj.constructDLL(arr);
        printList(ans);
    }
    return 0;
}

// } Driver Code Ends