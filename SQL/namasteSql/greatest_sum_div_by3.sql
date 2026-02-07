class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int total = 0;
        int m1 = INT_MAX, m2 = INT_MAX; // two smallest nums % 3 == 1
        int n1 = INT_MAX, n2 = INT_MAX; // two smallest nums % 3 == 2

        for (int x : nums) {
            total += x;
            if (x % 3 == 1) {
                if (x < m1) { m2 = m1; m1 = x; }
                else if (x < m2) m2 = x;
            } else if (x % 3 == 2) {
                if (x < n1) { n2 = n1; n1 = x; }
                else if (x < n2) n2 = x;
            }
        }

        if (total % 3 == 0) return total;
        int best = 0;
        if (total % 3 == 1) {
            if (m1 != INT_MAX) best = max(best, total - m1);
            if (n2 != INT_MAX) best = max(best, total - (n1 + n2));
        } else { // total % 3 == 2
            if (n1 != INT_MAX) best = max(best, total - n1);
            if (m2 != INT_MAX) best = max(best, total - (m1 + m2));
        }
        return best;
    }
};
