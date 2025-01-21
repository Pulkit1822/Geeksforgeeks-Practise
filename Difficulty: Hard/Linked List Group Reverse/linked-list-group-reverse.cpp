//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution {
public:
    Node* reverseKGroup(Node* head, int k) {
        if (k <= 1 || head == nullptr) return head; // No need to reverse
        
        Node* temp = head;
        vector<Node*> swp(k);
        int cnt = 0;

        while (temp != nullptr) {
            swp[cnt] = temp;
            cnt++;

            if (cnt == k) {
                // Reverse the group
                int left = 0, right = k - 1;
                while (left < right) {
                    swap(swp[left]->data, swp[right]->data);
                    left++;
                    right--;
                }
                cnt = 0; // Reset the counter for the next group
            }

            temp = temp->next;
        }

        // Reverse the remaining nodes if cnt > 0 and cnt < k
        if (cnt > 0 && cnt < k) {
            int left = 0, right = cnt - 1;
            while (left < right) {
                swap(swp[left]->data, swp[right]->data);
                left++;
                right--;
            }
        }

        return head;
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends