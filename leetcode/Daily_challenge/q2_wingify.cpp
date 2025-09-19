#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 1000001;
vector<bool> isPrime(MAXN, true);
vector<int> palPrimePrefix(MAXN, 0);

bool isPalindrome(int n) {
    int num = n, rev_num = 0;
    while (num > 0) {
        rev_num = rev_num * 10 + n % 10;
        num /= 10;
    }
    return num == rev_num;
}

void preprocess() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < MAXN; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < MAXN; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 1; i < MAXN; ++i) {
        palPrimePrefix[i] = palPrimePrefix[i - 1];
        if (isPrime[i] && isPalindrome(i)) {
            palPrimePrefix[i]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    preprocess();

    int T;
    cin >> T;
    while (T--) {
        int L, R;
        cin >> L >> R;
        L = max(1, L);
        R = min(R, MAXN - 1);
        int result = palPrimePrefix[R] - palPrimePrefix[L - 1];
        cout << result <<endl;
    }

    return 0;
}
