#define ll long long
class Solution {
public:
    ll maximumTotalDamageHelper (int spell, vector<int>& power, unordered_map<ll, ll>& spellFreq, vector<ll>& dp) {
        if (spell >= power.size()) {
            return 0;
        }
        else if (dp[spell] != -1) {
            return dp[spell];
        }
        int nextSpell = upper_bound(power.begin() + spell, power.end(), power[spell] + 2) - power.begin();
        ll spellUsed = maximumTotalDamageHelper(nextSpell, power, spellFreq, dp) + (power[spell] * spellFreq[power[spell]]);
        ll spellNotUsed = maximumTotalDamageHelper(spell + 1, power, spellFreq, dp);

        return dp[spell] = max(spellUsed, spellNotUsed);
    }
    long long maximumTotalDamage(vector<int>& power) {
        sort (power.begin(), power.end());
        vector<ll> dp (power.size() + 1, -1);
        unordered_map<ll, ll> spellFreq;

        for (int damage : power) {
            spellFreq[damage] += 1;
        }

        return maximumTotalDamageHelper (0, power, spellFreq, dp);
    }
};