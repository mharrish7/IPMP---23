//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int closestToZero(int arr[], int n)
        {
            sort(arr,arr+n);
            int l =0;
            int r = n - 1;
            int curmin = INT_MAX ;
            
            while(l < r){
                if(abs(curmin) == abs(arr[l] + arr[r])){
                    curmin = max(curmin,arr[l] + arr[r]);
                }
                else if(abs(curmin) > abs(arr[l] + arr[r])){
                    curmin = arr[l] + arr[r];
                }
                
                if(arr[l] + arr[r] > 0){
                    r--;
                }
                else{
                    l++;
                }
            }
            return curmin;
        }
};

//{ Driver Code Starts.
int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}
// } Driver Code Ends