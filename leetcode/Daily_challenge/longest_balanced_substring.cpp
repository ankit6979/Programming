class Solution {
public:
    bool checkCharCnt (vector<int>& freq) {
        int currCnt = -1;
        for (int idx = 0; idx < 26; ++idx) {
            if (freq[idx] != 0 && currCnt != -1) {
                if (freq[idx] != currCnt) {
                    return false;
                }
            }
            else if (freq[idx] != 0 && currCnt == -1) {
                currCnt = freq[idx];
            }
        }
        return true;
    }

    int longestBalanced(string s) {
        vector<int> freq (26, 0);
        int maxSubstringLen = 0;

        for (int i = 0; i < s.length(); ++i) {
            for (int j = i; j < s.length(); ++j) {
                freq[s[j] - 'a'] += 1;
                if (checkCharCnt (freq)) {
                    maxSubstringLen = max (maxSubstringLen, j - i + 1);
                }
            }
            fill(freq.begin(), freq.end(), 0);
        }

        return maxSubstringLen;
    }
};
