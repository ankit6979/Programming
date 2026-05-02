class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), permutation = 0, sum = 0;
        vector<int> dp (n, 0);
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            permutation += (nums[i] * i);
        }

        dp[0] = permutation;

        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1] + sum - (n * nums[n - i]);
            permutation = max (permutation, dp[i]);
        }

        return permutation;
    }
};