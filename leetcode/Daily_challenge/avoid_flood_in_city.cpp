class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, int> fullLakes;
        set<int> dryDays;
        int idx = 0;

        for (int day = 0; day < n; ++day) {
            if (rains[day] == 0) {
                dryDays.insert(day);
            }
            else {
                int lake = rains[day];
                if (fullLakes.count(lake)) {
                    auto it = dryDays.lower_bound(fullLakes[lake]);
                    if (it == dryDays.end()) {
                        return {};
                    }
                    ans[*it] = lake;
                    dryDays.erase(it);
                }
                ans[day] = -1;
                fullLakes[lake] = day;
            }
        }
        return ans;
    }
};