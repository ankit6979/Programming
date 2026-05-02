// O(3n) time and O(2n) space
class Solution {
public:
    int minimumDeletions(string s) {
        int minDeletion = INT_MAX;
        int size = s.length();
        vector<int> bBefore (size + 1, 0);
        vector<int> aAfter (size + 1, 0);

        for (int i = 1; i < s.length(); ++i) {
            if (s[i - 1] == 'b') {
                bBefore[i] = bBefore[i - 1] + 1;
            }
            else {
                bBefore[i] = bBefore[i - 1];
            }
        }

        for (int i = s.length() - 2; i >= 0; --i) {
            if (s[i + 1] == 'a') {
                aAfter[i] = aAfter[i + 1] + 1;
            }
            else {
                aAfter[i] = aAfter[i + 1];
            }
        }

        for (int i = 0; i < s.length(); ++i) {
            minDeletion = min (minDeletion, aAfter[i] + bBefore[i]);
        }

        return minDeletion;
    }
};

// O(2n) time and O(n) space
class Solution {
public:
    int minimumDeletions(string s) {
        int minDeletion = INT_MAX;
        int size = s.length(), aAfter = 0;
        vector<int> bBefore (size + 1, 0);

        for (int i = 1; i < s.length(); ++i) {
            if (s[i - 1] == 'b') {
                bBefore[i] = bBefore[i - 1] + 1;
            }
            else {
                bBefore[i] = bBefore[i - 1];
            }
        }

        for (int i = s.length() - 2; i >= 0; --i) {
            if (s[i + 1] == 'a') {
                aAfter += 1;
            }
            minDeletion = min (minDeletion, aAfter + bBefore[i]);
        }

        minDeletion = min (minDeletion, bBefore[s.length() - 1]);

        return minDeletion;
    }
};

// O( n) time and O(1) space
class Solution {
public:
    int minimumDeletions(string s) {
        int deletions = 0;
        int bCount = 0;

        for (char c : s) {
            if (c == 'b') {
                bCount++;
            } else { // c == 'a'
                deletions = min(deletions + 1, bCount);
            }
        }

        return deletions;
    }
};
