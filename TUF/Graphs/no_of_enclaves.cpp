class Solution {
public:
    void bfs(int start_x, int start_y, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        visited[start_x][start_y] = 1;
        q.push(make_pair(start_x, start_y));

        while (!q.empty()) {
            int curr_x = q.front().first;
            int curr_y = q.front().second;
            q.pop();

            for(int i = 0; i < 4; ++i) {
                int new_x = curr_x + dir[i][0];
                int new_y = curr_y + dir[i][1];
                if(new_x >= 0 && new_y >= 0 && new_x < grid.size() && new_y < grid[0].size()) {
                    if(grid[new_x][new_y] == 1 && visited[new_x][new_y] == -1) {
                        q.push(make_pair(new_x, new_y));
                        visited[new_x][new_y] = 1;
                    }
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int unreachable_cell = 0;
        vector<vector<int>> visited (rows, vector<int>(cols, -1));

        for (int i = 0; i < rows; ++i) {
            if(grid[i][0] == 1 && visited[i][0] == -1) {
                bfs(i, 0, grid, visited);
            }
            if(grid[i][cols - 1] == 1 && visited[i][cols - 1] == -1) {
                bfs(i, cols - 1, grid, visited);
            }
        }

        for (int i = 1; i < cols - 1; ++i) {
            if(grid[0][i] == 1 && visited[0][i] == -1) {
                bfs(0, i, grid, visited);
            }
            if(grid[rows - 1][i] == 1 && visited[rows - 1][i] == -1) {
                bfs(rows - 1, i, grid, visited);
            }
        }

        for(int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(grid[i][j] == 1 && visited[i][j] == -1) {
                    unreachable_cell += 1;
                }
            }
        }

        return unreachable_cell;
    }
};