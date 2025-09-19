class Solution {
    public: 
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            long long fairPairCnt = 0, totalNums = nums.size();
            sort(nums.begin(), nums.end());
            for(int firstNumIdx = 0; firstNumIdx < totalNums; ++firstNumIdx) {
                long long SecondNumLower = lower - nums[firstNumIdx];
                long long SecondNumUpper = upper - nums[firstNumIdx];
                long long lowerIdx = lower_bound(nums.begin() + firstNumIdx + 1, nums.end(), SecondNumLower) - nums.begin();
                long long upperIdx = upper_bound(nums.begin() + firstNumIdx + 1, nums.end(), SecondNumUpper) - nums.begin() - 1;
                fairPairCnt += (upperIdx - lowerIdx + 1);
            }
    
            return fairPairCnt;
        }
    };