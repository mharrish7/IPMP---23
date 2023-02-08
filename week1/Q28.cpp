class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        set<vector<int>> s;
        for(int i = 0 ; i < n-3; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j = i+1; j < n-2; j++){
                int l = j+1;
                int r = n-1;
                while(l < r){
                    long long int t = nums[i];
                    t += nums[j];
                    t += nums[l];
                    t += nums[r];
                    if(t < target){
                        l++;
                    }
                    else if(t > target){
                        r--;
                    }
                    else{
                        s.insert({nums[l],nums[r],nums[i],nums[j]});
                        l++;
                        r--;
                    }
                }
            }
        }
        for(auto x : s){
            res.push_back(x);
        }

        return res;
    }
};