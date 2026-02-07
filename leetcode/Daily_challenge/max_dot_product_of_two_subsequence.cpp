class Solution {
public:
    int maxDotProductHelper (vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) {
            return INT_MIN;
        }
        else if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int take = nums1[i] * nums2[j] + max(0, maxDotProductHelper(nums1, nums2, i - 1, j - 1, dp));
        int skipA = maxDotProductHelper(nums1, nums2, i - 1, j, dp);
        int skipB = maxDotProductHelper(nums1, nums2, i, j - 1, dp);

        return dp[i][j] = max({take, skipA, skipB});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp (nums1.size() + 1, vector<int> (nums2.size() + 1, -1));
        return maxDotProductHelper (nums1, nums2, nums1.size() - 1, nums2.size() - 1, dp);
    }
};