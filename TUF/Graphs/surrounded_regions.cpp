class Solution {
public:
    void bfs(int start_x, int start_y, vector<vector<char>>& board, vector<vector<int>>& visited) {
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        visited[start_x][start_y] = 1;
        q.push(make_pair(start_x, start_y));

        while(!q.empty()) {
            int curr_x = q.front().first;
            int curr_y = q.front().second;
            q.pop();

            for(int i = 0; i < 4; ++i) {
                int new_x = curr_x + dir[i][0];
                int new_y = curr_y + dir[i][1];
                if(new_x >= 0 && new_x < board.size() && new_y >= 0 && new_y < board[0].size()) {
                    if(board[new_x][new_y] == 'O' && visited[new_x][new_y] == -1) {
                        q.push(make_pair(new_x, new_y));
                        visited[new_x][new_y] = 1;
                    }
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, -1));

        for(int i = 0; i < rows; ++i) {
            if(board[i][0] == 'O') {
                bfs(i, 0, board, visited);
            }
            if(board[i][cols - 1] == 'O') {
                bfs(i, cols - 1, board, visited);
            }
        }
        for(int i = 1; i < cols - 1; ++i) {
            if(board[0][i] == 'O') {
                bfs(0, i, board, visited);
            }
            if(board[rows - 1][i] == 'O') {
                bfs(rows - 1, i, board, visited);
            }
        }

        for(int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(visited[i][j] == 1) {
                    board[i][j] = 'O';
                }
                else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};