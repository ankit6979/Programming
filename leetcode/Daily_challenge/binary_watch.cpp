class Solution {
public:
    void readBinaryWatchHelper(string& initialState, int idx, int turnedOn, set<string>& ans) {
        if (turnedOn == 0 || idx >= 10) {
            string hour = initialState.substr(0, 4);
            string minute = initialState.substr(4, 6);

            int hours = bitset<4>(hour).to_ulong();
            int minutes = bitset<6>(minute).to_ulong();

            // cout<<initialState<<" "<<hour<<" "<<minute<<" "<<hours<<" "<<minutes<<endl;

            if (hours <= 11 && minutes <= 59 && turnedOn == 0) {
                if (minutes < 10) {
                    ans.insert(to_string(hours) + ":0" + to_string(minutes));
                }
                else {
                    ans.insert(to_string(hours) + ":" + to_string(minutes));
                }
            }
            return;
        }
        readBinaryWatchHelper (initialState, idx + 1, turnedOn, ans);
        initialState[idx] = '1';
        readBinaryWatchHelper (initialState, idx + 1, turnedOn - 1, ans);
        initialState[idx] = '0';
    }
    vector<string> readBinaryWatch(int turnedOn) {
        if (turnedOn == 0) {
            return {"0:00"};
        }
        set<string> ans;
        vector<string> possibleTimes;
        string initialState = "0000000000";
        
        readBinaryWatchHelper(initialState, 0, turnedOn, ans);
        
        set<string>::iterator it = ans.begin();
        while (it != ans.end()) {
            if (*it != "0:00") {
                possibleTimes.push_back(*it);
            }
            it++;
        }
        return possibleTimes;
    }
};