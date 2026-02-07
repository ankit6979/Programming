#define ll long long
const double eps = 1e-5;
class Solution {
public:
    pair<double, double> calcArea (double y, vector<vector<int>>& squares) {
        double aboveArea = 0.0, belowArea = 0.0;

        for (int i = 0; i < squares.size(); ++i) {
            double length = static_cast<double>(squares[i][2]);
            if (squares[i][1] <= y && (squares[i][1] + squares[i][2]) > y) {
                double bottom = squares[i][1];
                double top = squares[i][1] + length;

                belowArea += length * (y - bottom);
                aboveArea += length * (top - y);
            }
            else if (squares[i][1] >= y) {
                aboveArea += (length * length);
            }
            else {
                belowArea += (length * length);
            }
        }

        return {belowArea, aboveArea};
    }
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18;
        double high = -1e18;

        for (auto &sq : squares) {
            low = min(low, (double)sq[1]);
            high = max(high, (double)sq[1] + sq[2]);
        }

        while (high - low > eps) {
            double mid = low + (high - low) / 2.0;
            auto area = calcArea(mid, squares);
            if (area.first >= area.second) {
                high = mid;
            } else {
                low = mid;
            }
        }

        return low;
    }
};