#define ll long long
class Solution {
public:
    int mod = 1e9+7;
    int numSub(string s) {
        int substrCount = 0;
        int left = 0, right = 0, strSize = s.length();

        while (left < strSize) {
            while (right < strSize && s[right] == '1') {
                right += 1;
            }
            ll currLen = (right - left);
            ll val = ((((currLen % mod) * (currLen + 1) % mod)) % mod) / 2;
            substrCount =  ((substrCount % mod) + (val % mod)) % mod;
            left = right + 1;
            right = left;
        }
        return substrCount;
    }
};