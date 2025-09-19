class Solution {
public:
    pair<int, int> getZigzagRowCol(int idx_val, int n) {
        int row = (idx_val - 1) / n;
        int col = (idx_val - 1) % n;

        if (row % 2 == 1) {
            col = n - col - 1;
        }
        row = n - row - 1;

        return {row, col};
    }
    int snakesAndLaddersHelper(vector<vector<int>>& board, vector<bool>& visited) {
        int n = board.size();
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int level = 0;
        int MAX = n * n;

        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                int curr_val = q.front();
                q.pop();

                if(curr_val == MAX) return level;

                for (int next = curr_val + 1; next <= min(curr_val + 6, MAX); ++next) {
                    int dest = next;
                    pair<int, int> next_idx = getZigzagRowCol(next, n);
                    if(board[next_idx.first][next_idx.second] != -1) {
                        dest = board[next_idx.first][next_idx.second];
                    }
                    if(!visited[dest]) {
                        q.push(dest);
                        visited[dest] = true;
                    }
                }
            }
            level++;
        }
        return -1;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int board_size = board.size();
        vector<bool> visited((board_size*board_size) + 1, false);
        return snakesAndLaddersHelper(board, visited);
    }
};