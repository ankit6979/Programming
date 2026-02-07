#define ll long long
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int wizards = skill.size();
        int potions = mana.size();
        vector<ll> timeRequired;

        ll currTime = 0;
        for (int wizard = 0; wizard < wizards; ++wizard) {
            currTime += (skill[wizard] * mana[0]);
            timeRequired.push_back(currTime);
        }
        
        for (int potion = 1; potion < potions; ++potion) {
            ll newPotionStartTime = timeRequired[0];
            currTime = 0;
            for (int wizard = 0; wizard < wizards - 1; ++wizard) {
                currTime += (skill[wizard] * mana[potion]);
                newPotionStartTime = max(newPotionStartTime, timeRequired[wizard + 1] - currTime);
            }

            timeRequired.clear();
            currTime = 0;
            for (int wizard = 0; wizard < wizards; ++wizard) {
                currTime += (skill[wizard] * mana[potion]);
                timeRequired.push_back(newPotionStartTime + currTime);
            }
        }

        return timeRequired[timeRequired.size() - 1];
    }
};