#define ll long long

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        ll prevVal = differences[0];

        ll lowerVal = max((ll)lower, lower - prevVal);
        ll upperVal = min((ll)upper, upper - prevVal);

        for (int i = 1; i < differences.size(); ++i) {
            lowerVal = max(lowerVal, lower - (prevVal + differences[i]));
            upperVal = min(upperVal, upper - (prevVal + differences[i]));
            prevVal = (prevVal + differences[i]);
        }
        
        if(upperVal < lowerVal) return 0;
        return (int)((upperVal - lowerVal) + 1);
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();