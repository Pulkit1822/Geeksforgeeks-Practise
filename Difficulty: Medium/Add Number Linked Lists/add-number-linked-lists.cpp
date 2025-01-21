//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:


struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution{
    private:
    Node* reverseLinkedList(Node* head){
        Node* current = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(current != NULL){
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
    
    void insertAtTail(Node* &head, Node* &tail, int val){
        Node* temp = new Node(val);
        
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
    }
    
    Node* add(Node* first, Node* second){
        int carry = 0;
        int sum = 0;
        int digit = 0;
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0){
            int value1 = 0, value2 = 0;
            if(first != NULL)
                value1 = first -> data;
            
            if(second != NULL)
                value2 = second -> data;
            
            sum = carry + value1 + value2;
            digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum/10;
            
            if(first != NULL)
                first = first -> next;
            
            if(second != NULL)
                second = second -> next;
        }
        
        return ansHead;
    }
    public:
    struct Node* addTwoLists(struct Node* num1, struct Node* num2){
        Node* first = reverseLinkedList(num1);
        Node* second = reverseLinkedList(num2);
        Node* ans = add(first, second);
        ans = reverseLinkedList(ans);
        while(ans -> data == 0 && ans->next != NULL ){
            ans = ans -> next;
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends