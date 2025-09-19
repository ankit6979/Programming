class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);

        string max_s = s;
        for(char c : s) {
            if(c != '9') {
                replace(max_s.begin(), max_s.end(), c, '9');
                break;
            }
        }

        string min_s = s;
        replace(min_s.begin(), min_s.end(), s[0], '0');

        return stoi(max_s) - stoi(min_s);
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();