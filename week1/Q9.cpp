//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int xor2 = 0;
        for(auto x : nums){
            xor2 = xor2^x;
        }
        
        int set = xor2 & ~(xor2-1);
        
        int a = 0;
        int b = 0;
        
        for(auto x : nums){
            if(x & set){
                a = a^x;
            }
            else{
                b = b^x;
            }
        }
        
        if(a > b){
            int t = a;
            a = b;
            b = t;
        }
        
        return {a,b};
        
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends