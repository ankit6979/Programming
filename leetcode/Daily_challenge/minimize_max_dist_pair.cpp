class Solution {
public:
    bool isPossible(vector<int>& nums, int p, int diff) {
        int pair_cnt = 0, i = 0;
        while (i < nums.size() - 1) {
            if(nums[i + 1] - nums[i] <= diff) {
                pair_cnt += 1;
                i += 1;
            }
            if(pair_cnt == p) {
                return true;
            }
            i += 1;
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int low = 0, mid = 0, high = nums[nums.size() - 1] - nums[0], min_max_distance;

        if(p == 0) return 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(nums, p, mid)) {
                min_max_distance = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return min_max_distance;
    }
};