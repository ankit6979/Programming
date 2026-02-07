#define ll long long
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<ll, ll> prefix_sum_map;
        ll prefix_sum = nums[0], max_sum = -4e17;
        prefix_sum_map[nums[0]] = nums[0];

        for (int right_idx = 1; right_idx < nums.size(); ++right_idx) {
            prefix_sum += nums[right_idx];
            if(prefix_sum_map.find(nums[right_idx] - k) != prefix_sum_map.end()) {
                max_sum = max(max_sum, (prefix_sum - prefix_sum_map[nums[right_idx] - k]) + nums[right_idx] - k);
            }
            if(prefix_sum_map.find(nums[right_idx] + k) != prefix_sum_map.end()) {
                max_sum = max(max_sum, (prefix_sum - prefix_sum_map[nums[right_idx] + k]) + nums[right_idx] + k);
            }
            if(prefix_sum_map.find(nums[right_idx]) != prefix_sum_map.end()) {
                prefix_sum_map[nums[right_idx]] = min (prefix_sum_map[nums[right_idx]], prefix_sum);
            }
            else {
                prefix_sum_map[nums[right_idx]] = prefix_sum;
            }
        }

        return max_sum == -4e17 ? 0 : max_sum;
    }
};
