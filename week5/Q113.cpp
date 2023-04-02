class Solution {
public:

    vector<int> prefix;
    Solution(vector<int>& w) {
        vector<int> a(w.size());
        a[0] = w[0];
        for(int i = 1; i < w.size(); i++){
            a[i] = a[i-1] + w[i];
        }
        prefix = a;
    }
    
    int pickIndex() {
        int ind = rand()%prefix[prefix.size() - 1];
        int res = upper_bound(prefix.begin(),prefix.end(),ind) - prefix.begin();
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */