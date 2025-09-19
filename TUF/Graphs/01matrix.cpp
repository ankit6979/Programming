class Solution {
public:
    void bfs(vector<vector<int>>& mat, vector<vector<int>>& visited) {
        queue<pair<int, int>> q;
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                if(mat[i][j] == 0) {
                    q.push(make_pair(i, j));
                    visited[i][j] = 0;
                }
            }
        }
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!q.empty()) {
            int curr_x = q.front().first;
            int curr_y = q.front().second;
            q.pop();

            for(int i = 0; i < dir.size(); ++i) {
                int new_x = curr_x + dir[i][0];
                int new_y = curr_y + dir[i][1];
                if(new_x >= 0 && new_y >= 0 && new_x < mat.size() && new_y < mat[0].size()) {
                    if(visited[new_x][new_y] == -1 && mat[new_x][new_y] == 1){
                        visited[new_x][new_y] = visited[curr_x][curr_y] + 1;
                        q.push(make_pair(new_x, new_y));
                    }
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> visited(row, vector<int>(col, -1));
        bfs(mat, visited);
        return visited;
    }
};