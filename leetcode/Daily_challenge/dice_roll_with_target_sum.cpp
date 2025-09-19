#define mod 1000000007
#define ll long long
class Solution {
public:
    int numRollsToTargetHelper(int dice, int k, int target, vector<vector<int>>& dp) {
        if(dice == 0 && target == 0) {
            return 1;
        }
        else if(target < 0 || (dice == 0)) {
            return 0;
        }
        else if(dp[dice][target] != -1) {
            return dp[dice][target];
        }
        int possible_ways = 0;
        for (int val = 1; val <= k; ++val) {
            possible_ways = ((possible_ways % mod) + (numRollsToTargetHelper(dice - 1, k, target - val, dp) % mod)) % mod;
        }
        return dp[dice][target] = possible_ways;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp (n + 1, vector<int>(target + 1, -1));
        return numRollsToTargetHelper(n, k, target, dp);
    }
};