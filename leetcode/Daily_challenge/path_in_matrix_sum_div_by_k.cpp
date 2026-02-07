#define modulo 1000000007
#define ll long long
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(k, 0));

        dp[0][grid[0][0] % k] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                
                vector<int> next_cell(k, 0);
                for (int r = 0; r < k; ++r) {
                    int val = grid[i][j];
                    // From top
                    if (i > 0 && dp[j][r] > 0) {
                        next_cell[(r + val) % k] = (next_cell[(r + val) % k] + dp[j][r]) % modulo;
                    }
                    // From left
                    if (j > 0 && dp[j - 1][r] > 0) {
                        next_cell[(r + val) % k] = (next_cell[(r + val) % k] + dp[j - 1][r]) % modulo;
                    }
                }
                dp[j] = next_cell;
            }
        }
        return dp[n - 1][0];
    }
};
