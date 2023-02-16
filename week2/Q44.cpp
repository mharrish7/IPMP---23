//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
class Solution{
  public:
    int maxLen(int arr[], int N)
    {
        vector<int> dp(N+1);
        dp[0] = 0;
        
        for(int i = 0; i < N; i++){
            int t;
            if(arr[i] == 1){
                t = 1;
            }
            else{
                t = -1;
            }
            dp[i+1] = dp[i] + t;
        }
        
        unordered_map<int,int> s;
        
        int res = 0;
        
        for(int i = 0; i < N+1; i++){
            int x = dp[i];
            if(s.find(x) != s.end()){
                res = max(res, i - s[x]);
            }
            else{
                s[x] = i;
            }
        }
        
        
        return res;
        
    }
};


//{ Driver Code Starts.

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends