class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq (26, 0);
        int min_deletion = INT_MAX;
        int deletion_required = 0, prev_sum = 0;

        for (auto c : word) {
            freq[c - 'a'] += 1;
        }

        freq.erase(remove(freq.begin(), freq.end(), 0), freq.end());

        sort(freq.begin(), freq.end());
        
        for (int i = 0; i < freq.size(); ++i) {
            deletion_required = prev_sum;
            for(int j = i + 1; j < freq.size(); ++j) {
                if(abs(freq[j] - freq[i]) > k) {
                    deletion_required += abs(freq[j] - freq[i]) - k;
                }
            }
            prev_sum += freq[i];
            min_deletion = min(min_deletion, deletion_required);
        }

        return min_deletion;
        
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();