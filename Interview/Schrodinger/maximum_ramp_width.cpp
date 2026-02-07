class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int max_width = -1;
        stack<int> s;

        for (int i = 0; i < nums.size(); ++i) {
            if(s.empty() || nums[i] <= nums[s.top()]) {
                s.push(i);
            }
        }

        for (int j = nums.size() - 1; j >= 0; --j) {
            while(!s.empty() && nums[j] >= nums[s.top()]) {
                max_width = max(max_width, j - s.top());
                s.pop();
            }
        }

        return max_width;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();