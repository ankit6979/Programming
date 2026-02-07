class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 1, precnt = 0, ans = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                ++cnt;
            } else {
                precnt = cnt;
                cnt = 1;
            }
            ans = max(ans, min(precnt, cnt));
            ans = max(ans, cnt / 2);
        }
        return ans >= k;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int low = 0, high = nums.size() / 2;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (hasIncreasingSubarrays(nums, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();