class Solution {
public:
    void dfs(int idx, int num, int n, vector<int>& ans) {
        if(num > n) {
            return;
        }
        for (int i = 0; i <= 9; ++i) {
            int curr_num = (num * 10) + i;
            if(curr_num <= n) {
                ans.emplace_back(curr_num);
                dfs(idx + 1, curr_num, n, ans);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1; i <= 9; ++i) {
            if(i <= n) {
                ans.emplace_back(i);
                dfs(1, i, n, ans);
            }
        }

        return ans;
    }
};