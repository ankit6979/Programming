class Solution {
public:
    int reverseBits(int n) {
        string binary_str = bitset<32>(n).to_string();
        reverse(binary_str.begin(), binary_str.end());
        int decimalNum = bitset<32>(binary_str).to_ulong();

        return decimalNum;
    }
};

// Optimal
class Solution {
public:
    int reverseBits(int n) {
        unsigned int result = 0;
        for (int i = 0; i < 32; i++) {
            result <<= 1;
            result |= (n & 1);
            n >>= 1;
        }
        return result;
    }
};