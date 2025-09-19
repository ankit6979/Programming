class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
            int noOfSubsets = 1 << (nums.size());
            int subsetXorSum = 0;
    
            for (int i = 0; i < noOfSubsets; ++i) {
                int xorVal = 0;
                for (int j = 0; j < nums.size(); ++j) {
                    if(i & (1 << j)) {
                        xorVal = xorVal ^ nums[j];
                    }
                }
                subsetXorSum += xorVal;
            }
    
            return subsetXorSum;
        }
    };
    auto init = []() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        return 'c';
    }();