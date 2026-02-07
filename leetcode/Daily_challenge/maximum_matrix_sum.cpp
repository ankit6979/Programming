#define ll long long
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll maxSum = 0;
        int negativeCnt = 0;
        int minVal = INT_MAX;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> negativeVals;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                maxSum += abs(matrix[row][col]);
                minVal = min (minVal, abs(matrix[row][col]));
                if (matrix[row][col] < 0) {
                    negativeCnt += 1;
                }
            }
        }

        if (negativeCnt % 2 != 0) {
            maxSum -= (2 * minVal);
        }

        return maxSum;
    }
};