class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int zeros = 0, left = 0, ans = 0;
        for (int right = 0; right < (int)nums.size(); ++right) {
            if (nums[right] == 0) ++zeros;
            while (zeros > 1) {
                if (nums[left] == 0) --zeros;
                ++left;
            }
            ans = std::max(ans, right - left);
        }
        return ans;
    }
};
