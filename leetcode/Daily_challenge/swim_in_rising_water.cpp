class Solution {
public:
    bool dfs (int row, int col, int rows, int cols, int time, vector<vector<int>>& directions, vector<vector<bool>>& visited, vector<vector<int>>& grid) {
        if (grid[row][col] > time) return false;
        stack<pair<int, int>> s;

        visited[row][col] = true;
        s.push({row, col});

        while (!s.empty()) {
            row = s.top().first;
            col = s.top().second;
            s.pop();
            
            for (auto &dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                
                if (newRow == rows - 1 && newCol == cols - 1) {
                    return grid[newRow][newCol] <= time;
                }

                if (newRow >= 0 && newCol >= 0 && newRow < rows && newCol < cols && !visited[newRow][newCol] && grid[newRow][newCol] <= time) {
                    visited[newRow][newCol] = true;
                    s.push({newRow, newCol});
                }
            }
        }

        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int low = 0;
        int high = INT_MIN;
        int min_time = INT_MAX;

        vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                high = max (grid[i][j], high);
            }
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;
            vector<vector<bool>> visited (rows, vector<bool> (cols, false));

            if (dfs(0, 0, rows, cols, mid, directions, visited, grid)) {
                high = mid - 1;
                min_time = min (min_time, mid);
            }
            else {
                low = mid + 1;
            }
        }

        return min_time == INT_MAX ? 0 : min_time;
    }
};