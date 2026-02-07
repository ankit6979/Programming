class Solution {
public:
    bool isPossible(vector<vector<int>>& charIdx, int low, int high, int j) {
        for (int i = 0; i < charIdx[j].size(); ++i) {
            if (charIdx[j][i] > low && charIdx[j][i] < high) {
                return true;
            }
        }
        return false;
    }
    int countPalindromicSubsequence(string s) {
        vector<vector<int>> charIdx (26);
        int subsequenceCnt = 0;

        for (int idx = 0; idx < s.length(); ++idx) {
            charIdx[s[idx] - 'a'].push_back(idx);
        }

        // for (int i = 0; i < 26; ++i) {
        //     if (charIdx[i].size() > 0) {
        //         for (int j = 0; j < charIdx[i].size(); ++j) {
        //             cout<<charIdx[i][j]<<" ";
        //         }
        //     }
        //     cout<<endl;
        // }

        for (int i = 0; i < 26; ++i) {
            if (charIdx[i].size() >= 2) {
                int low = charIdx[i][0];
                int high = charIdx[i][charIdx[i].size() - 1];
                for (int j = 0; j < 26; ++j) {
                    if (charIdx[j].size() > 0 && isPossible(charIdx, low, high, j)) {
                        // cout<<low<<" "<<high<<endl;
                        subsequenceCnt += 1;
                    }
                }
            }
        }
        return subsequenceCnt;
    }
};