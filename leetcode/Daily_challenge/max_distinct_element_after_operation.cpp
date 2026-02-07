class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int totalElements = nums.size();
        int totalDistinctElements, minUnused;

        sort (nums.begin(), nums.end());

        minUnused = nums[0] - k + 1;
        mpp[nums[0] - k] = 1;
        totalDistinctElements = 1;

        for (int idx = 1; idx < nums.size(); ++idx) {
            if ((nums[idx] - k) <= minUnused && minUnused <= (nums[idx] + k)) {
                mpp[minUnused] = 1;
                minUnused += 1;
                totalDistinctElements += 1;
            }
            else if (mpp.find(nums[idx]) == mpp.end()) {
                minUnused = max(minUnused, nums[idx] - k);
                mpp[minUnused] = 1;
                minUnused += 1;
                totalDistinctElements += 1;
            }
        }

        return totalDistinctElements;
    }
};

/* Optimized Code*/
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0, prev = INT_MIN;
        for (int num : nums) {
            int curr = min(max(num - k, prev + 1), num + k);
            if (curr > prev) {
                cnt++;
                prev = curr;
            }
        }
        return cnt;
    }
};