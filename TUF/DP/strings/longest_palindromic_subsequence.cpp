class Solution {
public:
    // int longestPalindromeSubseqHelper(int start, int end, string s, vector<vector<int>>& dp) {
    //     if(start == end) {
    //         return 1;
    //     }
    //     else if(start > end){
    //         return 0;
    //     }
    //     else if(dp[start][end] != -1) {
    //         return dp[start][end];
    //     }
    //     if(s[start] == s[end]) {
    //         return dp[start][end] = longestPalindromeSubseqHelper(start + 1, end - 1, s, dp) + 2;
    //     }
    //     int move_start = longestPalindromeSubseqHelper(start + 1, end, s, dp);
    //     int move_end = longestPalindromeSubseqHelper(start, end - 1, s, dp);
    //     return dp[start][end] = max(move_start, move_end);
    // }
    int longestPalindromeSubseq(string s) {
        int chars = s.size();
        string s1 = s;
        reverse(s1.begin(), s1.end());
        vector<vector<int>> dp(chars + 1, vector<int> (chars + 1, 0));
        // return longestPalindromeSubseqHelper(0, chars - 1, s, dp);
        for (int i = 1; i <= chars; ++i) {
            for (int j = 1; j <= chars; ++j) {
                if(s[i - 1] == s1[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[chars][chars];
    }
};