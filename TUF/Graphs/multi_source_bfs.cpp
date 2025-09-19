class Solution {
public:
    void bfs(queue<pair<int, int>>& q, vector<vector<int>>& grid, vector<vector<int>>& visited, int& max_time) {
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
        while(!q.empty()) {
            int curr_x = q.front().first;
            int curr_y = q.front().second;
            q.pop();

            for (auto& dir : directions) {
                int new_x = curr_x + dir.first;
                int new_y = curr_y + dir.second;

                if (new_x >= 0 && new_x < grid.size() && 
                    new_y >= 0 && new_y < grid[0].size() && 
                    visited[new_x][new_y] == INT_MAX && 
                    grid[new_x][new_y] == 1) {
                    
                    visited[new_x][new_y] = visited[curr_x][curr_y] + 1;
                    max_time = max(max_time, visited[new_x][new_y]);
                    q.push({new_x, new_y});
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int max_time = 0;
        queue<pair<int, int>> q;
        vector<vector<int>> visited(rows, vector<int> (cols, INT_MAX));
        for(int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                    visited[i][j] = 0;
                }
            }
        }
        bfs(q, grid, visited, max_time);

        for(int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(grid[i][j] == 1 && visited[i][j] == INT_MAX) {
                    return -1;
                }
            }
        }

        return max_time;
    }
};