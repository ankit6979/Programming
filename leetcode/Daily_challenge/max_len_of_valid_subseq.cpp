class Solution {
public:
    int maximumLengthHelper(int pos, vector<int>& nums, int parity, int mod_val, vector<vector<int>>& dp) {
        if(pos == nums.size()) {
            return 0;
        }
        else if(dp[pos][parity] != -1) {
            return dp[pos][parity];
        }
        if(parity == 0) {
            if(nums[pos] % 2 == mod_val) {
                return dp[pos][parity] = maximumLengthHelper(pos + 1, nums, parity, mod_val, dp) + 1;
            }
            else {
                return dp[pos][parity] = maximumLengthHelper(pos + 1, nums, parity, mod_val, dp);
            }
        }
        else if(parity == 1) {
            if(nums[pos] % 2 == mod_val) {
                return dp[pos][parity] = maximumLengthHelper(pos + 1, nums, parity, mod_val, dp) + 1;
            }
            else {
                return dp[pos][parity] = maximumLengthHelper(pos + 1, nums, parity, mod_val, dp);
            }
        }
        else if(parity == 2) {
            if(nums[pos] % 2 == mod_val) {
                if(mod_val == 0) {
                    mod_val = 1;
                }
                else {
                    mod_val = 0;
                }
                return dp[pos][parity] = maximumLengthHelper(pos + 1, nums, parity, mod_val, dp) + 1;
            }
            else {
                return dp[pos][parity] = maximumLengthHelper(pos + 1, nums, parity, mod_val, dp);
            }
        }
        else {
            if(nums[pos] % 2 == mod_val) {
                if(mod_val == 0) {
                    mod_val = 1;
                }
                else {
                    mod_val = 0;
                }
                return dp[pos][parity] = maximumLengthHelper(pos + 1, nums, parity, mod_val, dp) + 1;
            }
            else {
                return dp[pos][parity] = maximumLengthHelper(pos + 1, nums, parity, mod_val, dp);
            }
        }
    }
    int maximumLength(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int> (4, -1));
        int even_seq = maximumLengthHelper(0, nums, 0, 0, dp);
        int odd_seq = maximumLengthHelper(0, nums, 1, 1, dp);
        int odd_even_seq = maximumLengthHelper(0, nums, 2, 1, dp);
        int even_odd_seq = maximumLengthHelper(0, nums, 3, 0, dp);
        // cout<<even_seq<<" "<<odd_seq<<" "<<odd_even_seq<<" "<<even_odd_seq<<endl;
        return max({even_seq, odd_seq, odd_even_seq, even_odd_seq});
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();