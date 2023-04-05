//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxLength(string s)
    {
        if(s.size() == 0){
            return 0;
        }
        
        char A[s.size()];
        for(int i = 0 ; i < s.size(); i++) A[i] = '0';
        
        int len = 1;
        
        A[0] = s[0];
        
        for(int i = 1; i < s.size(); i++){
            auto it = lower_bound(A,A+len,s[i]);
            if(it == A + len){
                A[len++] = s[i];
            }
            else{
                *it = s[i];   
            }
            
        }
        
        return len;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout << ob.maxLength(S) << endl;
    }
    return 0; 
}
// } Driver Code Ends