#define ll long long
class Solution {
public:
    ll minimumDeleteSumHelper (string& s1, string& s2, int idx1, int idx2, vector<vector<ll>>& dp) {
        if (idx1 == 0 && idx2 == 0) {
            return 0;
        }
        else if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }
        else if (idx1 == 0) {
            return dp[idx1][idx2] = minimumDeleteSumHelper(s1, s2, idx1, idx2 - 1, dp) + static_cast<int>(s2[idx2 - 1]);
        }
        else if (idx2 == 0) {
            return dp[idx1][idx2] = minimumDeleteSumHelper(s1, s2, idx1 - 1, idx2, dp) + static_cast<int>(s1[idx1 - 1]);
        }
        else if (s1[idx1 - 1] == s2[idx2 - 1]){
            return dp[idx1][idx2] = minimumDeleteSumHelper(s1, s2, idx1 - 1, idx2 - 1, dp);
        }
        else {
            return dp[idx1][idx2] = min (
                minimumDeleteSumHelper(s1, s2, idx1 - 1, idx2, dp) + static_cast<int>(s1[idx1 - 1]),
                minimumDeleteSumHelper(s1, s2, idx1, idx2 - 1, dp) + static_cast<int>(s2[idx2 - 1])
            );
        }
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<ll>> dp (s1.length() + 1, vector<ll> (s2.length() + 1, -1));
        return (int)minimumDeleteSumHelper (s1, s2, s1.length(), s2.length(), dp);
    }
};