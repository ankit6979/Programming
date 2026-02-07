class Solution {
public:
    bool isMagicSquare(int row, int col, int size, vector<vector<int>>& grid) {
        int magicSum = -1;
        // Row sum
        for (int i = 0; i < size; ++i) {
            int currSum = 0;
            for (int j = 0; j < size; ++j) {
                currSum += grid[i + row][j + col];
            }

            if (magicSum == -1) {
                magicSum = currSum;
            }
            if (magicSum != -1 && currSum != magicSum) {
                return false;
            }
        }

        //col sum
        for (int j = 0; j < size; ++j) {
            int currSum = 0;
            for (int i = 0; i < size; ++i) {
                currSum += grid[i + row][j + col];
            }

            if (currSum != magicSum) {
                return false;
            }
        }

        //diagonal1 sum
        int i = 0, j = 0, currSum = 0;;
        while (i < size && j < size) {
            currSum += grid[i + row][j + col];
            ++i;
            ++j;
        }
        if (currSum != magicSum) {
            return false;
        }

        i = 0, j = size - 1, currSum = 0;;
        while (i < size && j >= 0) {
            currSum += grid[i + row][j + col];
            ++i;
            --j;
        }
        if (currSum != magicSum) {
            return false;
        }

        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int largestMagicSquareSize = 1;
        int maxPossibleSquareSize = min (grid.size(), grid[0].size());
        int rows = grid.size();
        int cols = grid[0].size();

        // isMagicSquare(1,1,3,grid);

        for (int size = 2; size <= maxPossibleSquareSize; ++size) {
            for (int row = 0; row < rows; ++row) {
                for (int col = 0; col < cols; ++col) {
                    if (row + size <= rows && col + size <= cols && isMagicSquare(row, col, size, grid)) {
                        largestMagicSquareSize = size;
                    }
                }
            }
        }

        return largestMagicSquareSize;
    }
};