//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    void swap(int* a, int*b){
        int t = *a;
        *a = *b;
        *b = t;
    }
	void rearrange(int arr[], int n) {
	    int p = 0;
	    int low = 0;
	    for(int current = 0; current < n; current++){
	        if(arr[current] < p){
	            swap(&arr[current],&arr[low++]);
	        }
	    }
	    
	    int l=0;
	    int r=low;

	    while(l < r){
	        if(l%2 == 0){
	            swap(&arr[l],&arr[r++]);
	        }
	        l++;
	    }
	   
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends