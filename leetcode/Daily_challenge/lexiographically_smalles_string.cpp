class Solution {
public:
    string rightRotate(const string& s, int b) {
        int n = s.size();
        if (n == 0) return s;
        b %= n;
        return s.substr(n - b) + s.substr(0, n - b);
    }

    string addToOddIndices(string& s, int a) {
        for (int i = 0; i < s.size(); ++i) {
            if (i % 2 == 1) { // odd index
                int val = (s[i] - '0' + a) % 10;
                s[i] = val + '0';
            }
        }
        return s;
    }

    string findLexSmallestString(string& s, int a, int b) {
        unordered_set<string> visited;
        string lexSmallestString = s;
        queue <string> q;

        q.push(s);
        visited.insert(s);

        while(!q.empty()) {
            string curr = q.front();
            q.pop();
            lexSmallestString = min (lexSmallestString, curr);

            string addStr = addToOddIndices(curr, a);
            if(!visited.count(addStr)) {
                visited.insert(addStr);
                q.push(addStr);
            }

            string rotatedString = rightRotate(curr, b);
            if(!visited.count(rotatedString)) {
                visited.insert(rotatedString);
                q.push(rotatedString);
            }
        }

        return lexSmallestString;
    }
};