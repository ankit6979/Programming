class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> pairs;
        sort (potions.begin(), potions.end());

        for (int spell : spells) {
            long long int requiredStrength = ceil((success * 1.0) / spell);
            int noOfPairs = potions.end() - lower_bound(potions.begin(), potions.end(), requiredStrength);
            pairs.push_back(noOfPairs);
        }

        return pairs;
    }
};