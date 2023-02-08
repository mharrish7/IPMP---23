//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int X)
    {   
        sort(arr, arr + n);
        for(int i = 0; i < n-3; i++){
            int l = i+1;
            int r = n-1;
            while(l < r){
                if(arr[l] + arr[r] + arr[i] > X){
                    r--;
                }
                else if(arr[l] + arr[r] + arr[i] < X){
                    l++;
                }
                else{
                    return true;
                }
            }
            
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends