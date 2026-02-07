class Solution {
public:
    int unsetBitNextToFirstZeroFromLSB(int x) {
        int firstZero = (~x) & (x + 1);
        if (firstZero == 0) {
            return x & (x >> 1);
        }
        return x & ~(firstZero >> 1);
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int num : nums) {
            if (num % 2 == 0) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(unsetBitNextToFirstZeroFromLSB(num));
            }
        }

        return ans;
    }
};