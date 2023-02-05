//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        int allxor = Arr[0];
        
        for(int i = 1 ; i < N ; i++){
            allxor = allxor^Arr[i];
        }

        int s2 = ~(allxor-1);
        int setbit = s2 & allxor;
        int a = 0;
        int b = 0;
        
        for(int i = 0; i < N; i++){
            if(setbit & Arr[i]){
                a = a^Arr[i];
            } 
            else{
                b = b^Arr[i];
            }
        }
        if(b > a){
            int t = b;
            b = a;
            a = t;
        }
        return {a,b};
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends