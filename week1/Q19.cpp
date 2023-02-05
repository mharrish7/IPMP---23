class Solution {
public:
    void swap(int* a ,int* b){
        int t = *a;
        *a = *b;
        *b = t;
    }
    void moveZeroes(vector<int>& nums) {
        for(int i = 0, l = 0; i < nums.size(); i++){
            if(nums[i] > 0 || nums[i] < 0){
                swap(&nums[i],&nums[l++]);
            }
        }
    }
};