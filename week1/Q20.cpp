class Solution {
public:
    int titleToNumber(string s) {
        if(s.length() == 1){
                return s[0] - 64;
        }
        else{
            int temp = s[s.size() - 1] - 64;
            s.pop_back();
            return  temp + 26*(titleToNumber(s));
        }
    };
};