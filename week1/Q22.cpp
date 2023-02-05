class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string rv = s;
        reverse(rv.begin(),rv.end());
        return s==rv;
    }
};