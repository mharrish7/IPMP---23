//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    
	    vector<long long int> dp(n);
	    dp[0] = arr[0];
	    
	    
	    vector<long long int> dp2(n);
	    dp2[0] = arr[0];
	   
	    
	    for(int i = 1; i < n; i++){
	        
	        dp[i] = max(dp[i-1]*arr[i],dp2[i-1]*arr[i]);
	        dp[i] = max(dp[i],(long long int)arr[i]);
	        dp2[i] = min(dp[i-1]*arr[i],dp2[i-1]*arr[i]);
	        dp2[i] = min(dp2[i],(long long int)arr[i]);
	        
	    }
	    
	 
	    return *max_element(dp.begin(),dp.end());
	    
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends