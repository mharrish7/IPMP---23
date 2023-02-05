//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

	void segregateEvenOdd(int arr[], int n) {
	    int l =0, r= n-1;
	    
	    while(l < r){
	        while(arr[l]%2==0 && l <r){
	            l++;
	        }
	        while(arr[r]%2 && l < r){
	            r--;
	        }
	        
	        int t = arr[l];
	        arr[l] = arr[r];
	        arr[r] = t;
	    }
	    sort(arr,arr+l);
	    sort(arr+l,arr+n);
	   
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.segregateEvenOdd(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends