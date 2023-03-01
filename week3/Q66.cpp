//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
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
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    struct Node* res = (struct Node*)malloc(sizeof(struct Node));
    struct Node* res2 = res;
    struct Node* cur1 = head1;
    struct Node* cur2 = head2;
    
    while(cur1 && cur2){
        if(cur1->data < cur2->data){
            cur1 = cur1->next;
        }
        else if(cur1->data > cur2->data){       
            cur2 = cur2->next;
        }
        else{
            res->next = cur1;
            res = res->next;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
    }
    
    res->next = NULL;
    
    return res2->next;
}