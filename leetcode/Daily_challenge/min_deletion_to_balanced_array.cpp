#define ll long long
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int minNumsToBeRemoved = INT_MAX;
        sort (nums.begin(), nums.end());

        for (int idx = 0; idx < nums.size(); ++idx) {
            ll maxAllowed = (ll)nums[idx] * (ll)k;
            int deletionRequired = nums.size() - (upper_bound(nums.begin() + idx, nums.end(), maxAllowed) - nums.begin());
            deletionRequired += idx;
            minNumsToBeRemoved = min (minNumsToBeRemoved, deletionRequired);
        }

        return minNumsToBeRemoved;
    }
};