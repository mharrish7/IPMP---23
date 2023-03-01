//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        struct Node* cur = head;
        struct Node* cur2 = head;
        int n = 0;
        struct Node* p = head;
        while(head){
            n++;
            head = head->next;
        }
        k = k%n;
        int k2 = k%n;
        while(k-- && cur2){
            cur2 = cur2->next;
        }
        struct Node* cur22 = cur2;
        
        while(cur2 && cur2->next){
            cur2 = cur2->next;
        }
        
        while(k2--){
            cur2->next = cur;
            cur = cur->next;
            cur2 = cur2->next;
        }
        cur2->next = NULL;
        
        return cur22;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends