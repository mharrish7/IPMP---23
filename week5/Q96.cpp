//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int nums[], int l, int r, int target){
        int l1 = l;
        int r1 = r;
        while(l1 <= r1){
            int m  = l1  + (r1-l1)/2 ;
            if(nums[m] == target){
                return m;
            }
            if(nums[m] >= nums[l]){
                if(nums[m] < target || target < nums[l]){
                    l1 = m +1;
                }
                else{
                    r1 = m - 1;
                }
            }
            else{
                if(nums[m] > target || target > nums[r]){
                    r1 = m - 1;
                }
                else{
                    l1 = m + 1;
                }
            }
            
        }
        return -1;
        
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends