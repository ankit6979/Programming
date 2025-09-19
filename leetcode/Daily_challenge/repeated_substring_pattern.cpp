class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string original_string = s;
        int rotate_by = 1;
        while(rotate_by < s.length()) {
            rotate(s.begin(), s.begin() + 1, s.end());
            if(original_string == s) {
                return true;
            }
            rotate_by += 1;
        }
        
        return false;
    }
};