int Solution::threeSumClosest(vector<int> &arr, int B) {
    sort(arr.begin(),arr.end());
    int dif = INT_MAX;
    int ans = 0;
    int n = arr.size();
    for(int i = 0; i < n-2; i++){
        int l = i+1;
        int r = n-1;
        while(l < r){
            int t = arr[l] + arr[r] + arr[i];
            if(t > B){
                r--;
            }
            else if(t < B){
                l++;
            }
            else{
                return B;
            }
            if(abs(t-B) < dif){
                dif = abs(t-B);
                ans = t;
            }
            
        }
        
    }
    return ans;
}
