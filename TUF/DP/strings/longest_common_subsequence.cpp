class Solution {
public:
    // int longestCommonSubsequenceHelper(int idx1, int idx2, string& text1, string& text2, vector<vector<int>>& dp) {
    //     if(idx1 < 0 || idx2 < 0) {
    //         return 0;
    //     }
    //     if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
    //     if(text1[idx1] == text2[idx2]) {
    //         return dp[idx1][idx2] = longestCommonSubsequenceHelper(idx1 - 1, idx2 - 1, text1, text2, dp) + 1;
    //     }
    //     int move_1 = longestCommonSubseq uenceHelper(idx1 - 1, idx2, text1, text2, dp);
    //     int move_2 = longestCommonSubsequenceHelper(idx1, idx2 - 1, text1, text2, dp);
    //     return dp[idx1][idx2] = max(move_1, move_2);
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int text1_len = text1.length();
        int text2_len = text2.length();
        // vector<vector<int>> dp(text1_len, vector<int> (text2_len, -1));
        // return longestCommonSubsequenceHelper(text1_len - 1, text2_len - 1, text1, text2, dp);
        vector<vector<int>> dp(text1_len + 1, vector<int> (text2_len + 1, 0));

        for(int i = 1; i <= text1_len; ++i) {
            for (int j = 1; j <= text2_len; ++j) {
                if(text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        for(int i = 0; i <= text1_len; ++i) {
            for (int j = 0; j <= text2_len; ++j) {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }

        return dp[text1_len][text2_len];
    }
};