//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        
        set<pair<int,int>> visited;
        vector<int> res;
        int i = 0;
        int j = 0;
        int di = 0;
        int dj = 1;
        for(int z = 0; z < r*c; z++){
            if(i+di == r || i+di < 0 || j + dj < 0 || j+dj == c || visited.find({i+di,j+dj}) != visited.end() ){
                int t = di;
                di = dj;
                dj = -t;
            }
            visited.insert({i,j});
            res.push_back(matrix[i][j]);
            i = i + di;
            j = j + dj;
        }
        
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends