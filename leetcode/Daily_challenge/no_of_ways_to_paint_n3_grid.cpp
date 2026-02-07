#define mod 1000000007
class Solution {
public:
    int numOfWaysHelper (vector<string>& states , int n, int prev, vector<vector<int>>& dp) {
        if (n == 0) {
            return 1;
        }

        else if (dp[n][prev] != -1) {
            return dp[n][prev];
        }

        int ans = 0;

        for (int idx = 0; idx < 12; ++idx) {
            if (states[prev][0] != states[idx][0] && states[prev][1] != states[idx][1] && states[prev][2] != states[idx][2]) {
                ans = (ans + numOfWaysHelper (states, n - 1, idx, dp)) % mod;
            }
        }
        return dp[n][prev] = ans;
    }
    int numOfWays(int n) {
        int totalNoOfWays = 0;
        vector<string> states = {"RYR", "YRY", "GRY", "RYG", "YRG", "GRG", "RGR", "YGR", "GYR", "RGY", "YGY", "GYG"};
        vector<vector<int>> dp (n + 1, vector<int> (12, -1));

        for (int idx = 0; idx < states.size(); ++idx) {
            totalNoOfWays = (totalNoOfWays + numOfWaysHelper(states, n - 1, idx, dp)) % mod;
        }

        return totalNoOfWays;
    }
};

// Time complexity = O(n * 12 * 12)
// Space complexity = O(n) + O(n)