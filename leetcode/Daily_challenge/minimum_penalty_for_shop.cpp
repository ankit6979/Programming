class Solution {
public:
    int bestClosingTime(string customers) {
        int minPenalty = INT_MAX;
        int earliestHour;
        vector<int> customerVisited (customers.size() + 1, 0);
        vector<int> customerNotVisited (customers.size() + 1, 0);

        for (int hour = customers.size() - 1; hour >= 0; --hour) {
            if (customers[hour] == 'Y') {
                customerVisited[hour] = customerVisited[hour + 1] + 1;
            }
            else {
                customerVisited[hour] = customerVisited[hour + 1];
            }
        }

        for (int hour = 1; hour <= customers.size(); ++hour) {
            if (customers[hour - 1] == 'N') {
                customerNotVisited[hour] = customerNotVisited[hour - 1] + 1;
            }
            else {
                customerNotVisited[hour] = customerNotVisited[hour - 1];
            }
        }

        for (int i = 0; i <= customers.size(); ++i) {
            if (customerVisited[i] + customerNotVisited[i] < minPenalty) {
                minPenalty = customerVisited[i] + customerNotVisited[i];
                earliestHour = i;
            }
        }

        return earliestHour;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();