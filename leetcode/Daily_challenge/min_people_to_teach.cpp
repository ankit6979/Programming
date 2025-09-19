class Solution {
public:
    bool canTalk(int friend1, int friend2, vector<vector<int>>& languages) {
        for (int i = 0; i < languages[friend1].size(); ++i) {
            for (int j = 0; j < languages[friend2].size(); ++j) {
                if(languages[friend2][j] == languages[friend1][i]) {
                    return true;
                }
            }
        }
        return false;
    }
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        set<int> cant_talk;
        map<int, int> mpp;
        int min_person_to_be_taught = INT_MAX;

        for (int friendship = 0; friendship < friendships.size(); ++friendship) {
            if(!canTalk(friendships[friendship][0] - 1, friendships[friendship][1] - 1, languages)) {
                cant_talk.insert(friendships[friendship][0] - 1);
                cant_talk.insert(friendships[friendship][1] - 1);
            }
        }

        set<int>:: iterator it = cant_talk.begin();

        int total_persons = cant_talk.size();

        while(it != cant_talk.end()) {
            for (int language = 0; language < languages[*it].size(); ++language) {
                mpp[languages[*it][language]] += 1;
                min_person_to_be_taught = min(min_person_to_be_taught, total_persons - mpp[languages[*it][language]]);
            }
            it++;
        }

        return min_person_to_be_taught == INT_MAX ? 0 : min_person_to_be_taught;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();