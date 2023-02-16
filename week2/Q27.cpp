//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRow(int N, int M, vector<vector<int>> arr) {
        
        
        for(int i = 0; i < N; i++){
            int no = 0;
            for(int j = 0; j < M ; j++){
                if(arr[i][j] == 1){
                    no++;
                }
            }
            arr[i][0] = no;
        }
        
        int min1 = INT_MAX;
        int res = -1;
        for(int i = 0; i < N; i++){
            if(min1 > arr[i][0]){
                res = i;
                min1 = arr[i][0];
            }
        }
        
        return res+1;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(N, M, A) << "\n";
    }
}
// } Driver Code Ends