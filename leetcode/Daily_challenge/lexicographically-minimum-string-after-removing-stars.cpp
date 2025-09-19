class Solution {
public:
    class Node {
        public:
            int idx;
            char c;
            Node (int x, char ch) : idx(x), c(ch) {};
    };
    class compareNode {
        public:
            bool operator() (const Node& a, const Node& b) {
                if(a.c == b.c) {
                    return a.idx < b.idx;  // Higher idx first (descending)
                }
                return a.c > b.c;          // Lower char first (ascending)
            }
    };
    string clearStars(string s) {
        priority_queue<Node, vector<Node>, compareNode> pq;
         vector<bool> keep(s.length(), false);
        for (int i = 0; i < s.size(); ++i) {
            if(s[i] == '*') {
                if(!pq.empty()) {
                    keep[pq.top().idx] = false;
                    pq.pop();
                }
            }
            else {
                keep[i] = true;
                pq.push(Node(i, s[i]));
            }
        }
        string ans = "";
        for (int i = 0; i < s.size(); ++i) {
            if (keep[i]) ans += s[i];
        }

        return ans;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();