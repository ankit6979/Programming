class Solution {
public:
    void findPSE(int row, int col, vector<vector<int>>& grid, vector<int>& pse) {
        stack<int> st;
        for(int i = 0; i < col; ++i) {
            while(!st.empty() && grid[row][st.top()] >= grid[row][i]) {
                st.pop();
            }
            if(st.empty()) {
                pse[i] = -1;
            }
            else {
                pse[i] = st.top();
            }
            st.push(i);
        }
    }
    void findNSE(int row, int col, vector<vector<int>>& grid, vector<int>& nse) {
        stack<int> st;
        for(int i = col - 1; i >= 0; --i) {
            while(!st.empty() && grid[row][st.top()] > grid[row][i]) {
                st.pop();
            }
            if(st.empty()) {
                nse[i] = col;
            }
            else {
                nse[i] = st.top();
            }
            st.push(i);
        }
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int max_area = 0;
        vector<vector<int>> grid(row, vector<int> (col));

        for (int i = 0; i < col; ++i) {
            if (matrix[0][i] == '0') {
                grid[0][i] = 0;
            }
            else {
                grid[0][i] = 1;
            }
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '0') {
                    grid[i][j] = 0;
                }
                else {
                    grid[i][j] = (matrix[i][j] - '0') + grid[i - 1][j];
                }
            }
        }

        for (int i = 0; i < row; ++i) {
            vector<int> pse (col);
            vector<int> nse (col);
            findPSE(i, col, grid, pse);
            findNSE(i, col, grid, nse);
            for (int j = 0; j < col; ++j) {
                int curr_area = (nse[j] - pse[j] - 1) * grid[i][j];
                max_area = max(max_area, curr_area);
            }
        }

        return max_area;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();