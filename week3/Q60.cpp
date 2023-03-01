//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
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

class Solution{
  public:
    //Function to check whether the list is palindrome.
    struct Node* reverseList(struct Node *head)
    {
        struct Node* prev = NULL;
        struct Node* current = head;
        
        while(current){
            struct Node* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        struct Node* root = prev;
        
        return prev;
    }
    bool isPalindrome(Node *head)
    {
        struct Node* slow = head;
        struct Node* fast = head;
        
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        slow = reverseList(slow);
        
        struct Node* p1 = head;
        
        while(slow && slow->data == p1->data){
            slow = slow->next;
            p1 = p1->next;
        }
        
        if(slow){
            return false;
        }
        else{
            return true;
        }
        
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends