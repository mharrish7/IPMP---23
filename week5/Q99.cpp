class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0;
        int r = letters.size();
        while(l < r){
            int m = l + (r-l)/2;
            if(letters[m] > target){
                r = m;
            }
            else{
                l = m +1;
            }
        }
        if(l < 0 or l >= letters.size()){
            return letters[0];
        }
        return letters[l];    
    }
};