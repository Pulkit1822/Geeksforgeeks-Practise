//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        if(head == NULL)     // agr koi node nhi he to
        {
            return new Node(x); // bs 1 new node bna denge usi xue ki 
        }
    
        Node* temp = head;    // nhi to 1 temp node lenge jo traverse kregi end of LL tk
        while(temp->next != NULL)    // tb tk traverse jb temp ke age wala node NULL ko na point kre
        {
            temp = temp->next;
        }
        Node* newNode = new Node(x);     //jb while loop complete ho jayega to temp ke age wala NULL hoga, isliye ab 1 new node bnayenge phle jis xue ko add krna he or use null ko point krayenge fir
        temp->next = newNode;    //fir temp ke next jo filhal NULL ko point kr raha tha use newNode pe point out kra denge
        return head;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        int x;
        cin >> x;
        cin.ignore();

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }

        Solution ob;
        Node* ans = ob.insertAtEnd(head, x);
        printList(ans);
    }

    return 0;
}
// } Driver Code Ends