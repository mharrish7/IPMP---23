class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0;
        int r = arr.size()-1;

        while(l < r){
            int m = l + (r-l)/2;
            if(arr[m+1] < arr[m]){
                r = m;
            }
            else{
                l = m +1;
            }
        }

        return r;
    }
};