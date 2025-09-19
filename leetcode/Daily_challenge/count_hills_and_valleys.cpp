class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int no_of_hills = 0, no_of_valleys = 0;
        vector<int> clean;

        for(int i = 0; i < nums.size(); ++i) {
            if(i == 0 || nums[i] != nums[i - 1]) {
                clean.push_back(nums[i]);
            }
        }

        for(int i = 1; i < clean.size() - 1; ++i) {
            if(clean[i - 1] < clean[i] && clean[i + 1] < clean[i]) {
                no_of_hills += 1;
            }
            if(clean[i - 1] > clean[i] && clean[i + 1] > clean[i]) {
                no_of_valleys += 1;
            }
        }
        return no_of_hills + no_of_valleys;
    }
};