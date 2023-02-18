//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    int gcd(int a, int b)
    {
    if (b == 0)
        return a;
 
    else
        return gcd(b, a % b);
    }
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        d = d%n;
        int g_c_d = gcd(d, n);
        for(int i = 0; i < g_c_d; i++){
            int t = i;
            int temp = arr[t];
            t = t + d;
            int t1 = i;
            while(1){
                if(t >= n){
                    t = t - n;
                }
                if(t == i){
                    break;
                }
                arr[t1] = arr[t];
                t1 = t;
                t+=d;
            }
            
            arr[t1] = temp;
        }
        
        
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n, d;
	    
	    //input n and d
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    //calling rotateArr() function
	    ob.rotateArr(arr, d,n);
	    
	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}
// } Driver Code Ends