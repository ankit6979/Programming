class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        unordered_set<int> s;
        int evenCnt = 0, oddCnt = 0;
        int maxSubarrayLen = 0;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                if (nums[j] % 2 == 0 && s.find(nums[j]) == s.end()) {
                    evenCnt += 1;
                }
                else if (nums[j] % 2 == 1 && s.find(nums[j]) == s.end()){
                    oddCnt += 1;
                }
                if (evenCnt == oddCnt) {
                    maxSubarrayLen = max (maxSubarrayLen, j - i + 1);
                }
                s.insert(nums[j]);
            }
            s.clear();
            evenCnt = 0, oddCnt = 0;
        }

        return maxSubarrayLen;
    }
};