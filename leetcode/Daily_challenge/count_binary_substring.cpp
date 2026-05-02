class Solution {
public:
    int countBinarySubstrings(string s) {
        int cntSubstring = 0, cntZero = 0, cntOne = 0;

        for (int i = 0; i < s.length() - 1; ++i) {
            if (s[i] == '0') {
                cntZero = 1;
                cntOne = 0;
                int j = i + 1;
                while(j < s.length() && s[j] == '0') {
                    cntZero += 1;
                    ++j;
                }
                while(j < s.length() && s[j] == '1') {
                    cntOne += 1;
                    ++j;
                    if (cntZero == cntOne) {
                        cntSubstring += 1;
                        break;
                    }
                }
            }
            else {
                cntZero = 0;
                cntOne = 1;
                int j = i + 1;
                while(j < s.length() && s[j] == '1') {
                    cntOne += 1;
                    ++j;
                }
                while(j < s.length() && s[j] == '0') {
                    cntZero += 1;
                    ++j;
                    if (cntZero == cntOne) {
                        cntSubstring += 1;
                        break;
                    }
                }
            }
        }

        return cntSubstring;
    }
};


/* Optimized One */
class Solution {
public:
    int countBinarySubstrings(string s) {
        int prevGroup = 0;
        int currGroup = 1;
        int result = 0;

        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i - 1]) {
                currGroup++;
            } else {
                result += min(prevGroup, currGroup);
                prevGroup = currGroup;
                currGroup = 1;
            }
        }

        result += min(prevGroup, currGroup);
        return result;
    }
};