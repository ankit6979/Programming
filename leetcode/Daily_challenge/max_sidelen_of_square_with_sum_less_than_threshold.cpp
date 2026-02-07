class Solution {
public:
    bool isPossible (int rows, int cols, int size, int threshold, vector<vector<int>>& prefixSum) {
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (row + size <= rows && col + size <= cols) {
                    int prevCol = col - 1; 
                    int nextCol = col + size - 1;
                    int totalSum = 0;

                    for (int idx = 0; idx < size; ++idx) {
                        totalSum += prefixSum[idx + row][nextCol];
                        if (prevCol >= 0) {
                            totalSum -= prefixSum[idx + row][prevCol];
                        }
                    }

                    if (totalSum <= threshold) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows = mat.size();
        int cols = mat[0].size();
        int maxSide = min(rows, cols);
        int possibleSide = 0;
        vector<vector<int>> prefixSum(rows, vector<int> (cols, 0));

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (col == 0) {
                    prefixSum[row][col] = mat[row][col];
                }
                else {
                    prefixSum[row][col] = prefixSum[row][col - 1] + mat[row][col];
                }
            }
        }

        int low = 0, high = maxSide;

        while (low <= high) {
            int mid = (low + high)/2;
            if (isPossible(rows, cols, mid, threshold, prefixSum)) {
                possibleSide = mid;
                low = mid + 1;            
            }
            else {
                high = mid - 1;
            }
        }
        
        return possibleSide;
    }
};