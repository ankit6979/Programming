class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long maxArea = 0;

        int points = bottomLeft.size();

        for (int i = 0; i < points; ++i) {
            for (int j = i + 1; j < points; ++j) {
                int currBottomX = bottomLeft[j][0];
                int currBottomY = bottomLeft[j][1];
                int currTopX = topRight[j][0];
                int currTopY = topRight[j][1];

                int ix1 = max(bottomLeft[i][0], currBottomX);
                int iy1 = max(bottomLeft[i][1], currBottomY);
                int ix2 = min(topRight[i][0], currTopX);
                int iy2 = min(topRight[i][1], currTopY);
                if (ix1 < ix2 && iy1 < iy2) {
                    long long side = min(ix2 - ix1, iy2 - iy1);
                    maxArea = max (maxArea, side*side);
                }
            }
        }

        return maxArea;
    }
};