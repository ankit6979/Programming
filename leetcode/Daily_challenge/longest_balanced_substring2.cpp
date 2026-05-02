class Solution {
public:
    int countOneDistinctChar (string s) {
        int maxSingleCharLen = 1, currLen = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i - 1]) {
                currLen += 1;
                maxSingleCharLen = max (maxSingleCharLen, currLen);
            }
            else {
                currLen = 1;
            }
        }
        return maxSingleCharLen;
    }
    int countTwoDistinctChar (string s, char c1, char c2) {
        int countC1 = 0, countC2 = 0, maxTwoCharLen = 0;
        unordered_map<int, int> mpp;
        mpp[0] = -1;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == c1) countC1 += 1; 
            else if (s[i] == c2) countC2 += 1;
            else {
                countC1 = 0;
                countC2 = 0;
                mpp.clear();
                mpp[0] = i;
                continue;
            }

            int diff = countC2 - countC1;
            if (mpp.find(diff) != mpp.end()) {
                maxTwoCharLen = max (maxTwoCharLen, i - mpp[diff]);
            }
            else {
                mpp[diff] = i;
            }
        }
        return maxTwoCharLen;
    }
    int countThreeDistinctChar (string s) {
        int countA = 0, countB = 0, countC = 0, maxThreeCharLen = 0;
        map<pair<int, int>, int> mpp;
        mpp[{0, 0}] = -1;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'a') countA += 1; 
            else if (s[i] == 'b') countB += 1;
            else if (s[i] == 'c') countC += 1;

            int diff1 = countB - countA;
            int diff2 = countC - countA;
            if (mpp.find({diff1, diff2}) != mpp.end()) {
                maxThreeCharLen = max (maxThreeCharLen, i - mpp[{diff1, diff2}]);
            }
            else {
                mpp[{diff1, diff2}] = i;
            }
        }
        return maxThreeCharLen;
    }
    int longestBalanced(string s) {
        int maxOneCharLen = countOneDistinctChar (s);
        int maxTwoCharLen = max ({countTwoDistinctChar (s, 'a', 'b'), countTwoDistinctChar (s, 'a', 'c'), countTwoDistinctChar (s, 'b', 'c')});
        int maxThreeCharLen = countThreeDistinctChar (s);

        return max ({maxOneCharLen, maxTwoCharLen, maxThreeCharLen});
    }
};
