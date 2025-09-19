class Solution {
public:
    void largestTimeFromDigitsHelper(vector<int>& arr, vector<pair<string, string>>& possible_times, vector<int>& visited, string& curr_time) {
        if(curr_time.size() == 4) {
            if(curr_time[0] == '0' || curr_time[0] == '1' || curr_time[0] == '2') {
                if(curr_time[0] == '2') {
                    if(curr_time[1] == '0' || curr_time[1] == '1' || curr_time[1] == '2' || curr_time[1] == '3') {
                        if(curr_time[2] == '0' || curr_time[2] == '1' || curr_time[2] == '2' || curr_time[2] == '3' || curr_time[2] == '4' || curr_time[2] == '5') {
                            possible_times.push_back(make_pair(curr_time.substr(0, 2), curr_time.substr(2, 2)));
                        }
                    }
                }
                else {
                    if(curr_time[2] == '0' || curr_time[2] == '1' || curr_time[2] == '2' || curr_time[2] == '3' || curr_time[2] == '4' || curr_time[2] == '5') {
                        possible_times.push_back(make_pair(curr_time.substr(0, 2), curr_time.substr(2, 2)));
                    }
                }
            }
        }
        for(int i = 0; i < arr.size(); ++i) {
            if(visited[i] == -1) {
                curr_time.push_back(arr[i] + '0');
                visited[i] = 1;
                largestTimeFromDigitsHelper(arr, possible_times, visited, curr_time);
                curr_time.pop_back();
                visited[i] = -1;
            }
        }
    }
    // struct Compare {
    //     bool operator() (const pair<string, string>& a, const pair<string, string>& b) {
    //         if(a.first == b.first) {
    //             return a.second > b.second;
    //         }
    //         return a.first > b.first;
    //     }
    // };
    string largestTimeFromDigits(vector<int>& arr) {
        vector<pair<string, string>> possible_times;
        bool ispossible = false;
        vector<int> visited(4, -1);
        string curr_time = "";
        largestTimeFromDigitsHelper(arr, possible_times, visited, curr_time);

        sort(possible_times.rbegin(), possible_times.rend());
        
        if(possible_times.size()) {
            return possible_times[0].first + ":" + possible_times[0].second;
        }
        return "";
    }
};

// optimal //
class Solution {
public:
    void largestTimeFromDigitsHelper(vector<int>& arr, vector<int>& visited, string& curr_time, string& best_time) {
        if(curr_time.size() == 4) {
            int hour = stoi(curr_time.substr(0, 2));
            int minute = stoi(curr_time.substr(2, 2));
            if(hour < 24 && minute < 60) {
                string candidate = curr_time;
                if(candidate > best_time) {
                    best_time = candidate;
                }
            }
            return;
        }
        for(int i = 0; i < arr.size(); ++i) {
            if(visited[i] == -1) {
                curr_time.push_back(arr[i] + '0');
                visited[i] = 1;
                largestTimeFromDigitsHelper(arr, visited, curr_time, best_time);
                curr_time.pop_back();
                visited[i] = -1;
            }
        }
    }
    string largestTimeFromDigits(vector<int>& arr) {
        vector<int> visited(4, -1);
        string curr_time = "";
        string best_time = "";
        largestTimeFromDigitsHelper(arr, visited, curr_time, best_time);
        if(best_time.empty()) return "";
        return best_time.substr(0, 2) + ":" + best_time.substr(2, 2);
    }
};