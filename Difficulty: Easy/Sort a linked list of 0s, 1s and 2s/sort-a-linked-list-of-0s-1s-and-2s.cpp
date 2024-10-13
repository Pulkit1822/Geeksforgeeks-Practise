//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends
/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {    // normal Brute force approach

        // Add code here
        
        if(head == NULL)     return NULL;
        
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;    //phle count krenge ki kitne no of 0's ,1's, and 2's he
        Node* temp = head;
        while(temp != NULL)
        {
            if(temp->data == 0)          cnt0++;     
            else if(temp->data == 1)     cnt1++;
            else                         cnt2++;
            temp = temp->next;
        }
        
        temp = head;            //Now again traverse and do the data replacement
        while(temp != NULL) 
        {
            if(cnt0){              //jb tk cnt0 me value hogi(i.e grater than 0)
                temp->data = 0;  // tb tk temp ki val pe 0 assign krna he
                cnt0--;          // or cnt of 0 km krna he
            }
            else if(cnt1)          // same as above
            {
                temp->data = 1;
                cnt1--;
            }
            else{                          //same as above
                temp->data = 2;
                cnt2--;
            }
            temp = temp->next;           
        }
        return head;                        // and we're all set
    }
};



//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends