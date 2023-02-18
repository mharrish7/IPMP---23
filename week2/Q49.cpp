class Solution {
public:
    int solve(vector<int>&nums, int k){
        unordered_map<int,int> hast;
        int l = 0, r = 0;
        int res = 0;
        while(r < nums.size()){
            hast[nums[r]]++;
            
            while(hast.size() > k){
                hast[nums[l]]--;
                if(hast[nums[l]] == 0){
                    hast.erase(nums[l]);
                }
                l+=1;
            }
                
            res += (r-l+1);
            r+=1;
        }

        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
    }
};