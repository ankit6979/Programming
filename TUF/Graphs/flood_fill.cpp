class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int rows = image.size();
        int cols = image[0].size();
        int src_color = image[sr][sc];
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        visited[sr][sc] = 1;

        while(!q.empty()) {
            int curr_x = q.front().first;
            int curr_y = q.front().second;
            q.pop();
            image[curr_x][curr_y] = color;

            for (auto& dir : directions) {
                int new_x = curr_x + dir.first;
                int new_y = curr_y + dir.second;
                if(new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols && image[new_x][new_y] == src_color && visited[new_x][new_y] == 0) {
                    visited[new_x][new_y] = 1;
                    q.push(make_pair(new_x, new_y));
                }
            }
        }

        return image;
    }
};