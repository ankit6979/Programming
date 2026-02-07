// O(m*n)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int negativeCount = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] < 0) {
                    ++negativeCount;
                }
            }
        }

        return negativeCount;
    }
};

// O(m*log(n))
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int negativeCount = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int row = 0; row < rows; ++row) {
            int idx = upper_bound(grid[row].begin(), grid[row].end(), 0, greater<int>()) - grid[row].begin();
            // cout<<idx<<endl;
            negativeCount += (cols - idx);
        }

        return negativeCount;
    }
};

// O(m + n)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int negativeCount = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int col = 0;

        for (int row = rows - 1; row >= 0; --row) {
            while (col< cols && grid[row][col] >= 0) {
                col += 1;
            }
            negativeCount += (cols - col);
        }

        return negativeCount;
    }
};