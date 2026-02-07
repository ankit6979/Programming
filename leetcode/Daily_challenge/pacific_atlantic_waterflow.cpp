class Solution {
public:
    void dfs(int row, int col, int rows, int cols, vector<vector<int>>& heights, vector<vector<bool>>& visited, vector<vector<int>>& directions) {
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
                
                if (newRow >= 0 && newCol >= 0 && newRow < rows && newCol < cols && !visited[newRow][newCol] && heights[newRow][newCol] >= heights[row][col]) {
                    visited[newRow][newCol] = true;
                    s.push({newRow, newCol});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> visitedAtlantic (rows, vector<bool> (cols, false));
        vector<vector<bool>> visitedPacific (rows, vector<bool> (cols, false));
        vector<vector<int>> isPossible;
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int col = 0; col < cols; ++col) {
            if (!visitedPacific[0][col]) {
                dfs (0, col, rows, cols, heights, visitedPacific, directions);
            }
            if (!visitedAtlantic[rows - 1][col]) {
                dfs (rows - 1, col, rows, cols, heights, visitedAtlantic, directions);
            }
        }

        for (int row = 0; row < rows; ++row) {
            if (!visitedPacific[row][0]) {
                dfs (row, 0, rows, cols, heights, visitedPacific, directions);
            }
            if (!visitedAtlantic[row][cols - 1]) {
                dfs (row, cols - 1, rows, cols, heights, visitedAtlantic, directions);
            }
        }

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (visitedPacific[row][col] && visitedAtlantic[row][col]) {
                    isPossible.push_back({row, col});
                }
            }
        }
        
        return isPossible;
    }
};