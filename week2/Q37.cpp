//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDiagonal(int N, vector<vector<int>> A)
	{
		
		vector<int> res;
		
		for(int i =0; i < A[0].size(); i++){
		    int t = 0;
		    int t1 = i;
		    
		    while(t < A.size() && t1 >= 0){
		        res.push_back(A[t][t1]);
		        t1--;
		        t++;
		    }
		    
		}
		
		for(int i = 1; i < A.size(); i++){
		    int t = i;
		    int t1 = A[0].size()-1;
		    
		    while(t < A.size() && t1 >= 0){
		        res.push_back(A[t][t1]);
		        t1--;
		        t++;
		    }
		}
		
		return res;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDiagonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends