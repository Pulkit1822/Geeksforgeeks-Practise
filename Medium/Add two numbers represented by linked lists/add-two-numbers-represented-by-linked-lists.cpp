//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
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

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
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

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends