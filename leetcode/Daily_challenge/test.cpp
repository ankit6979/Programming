#include <bits/stdc++.h>
using namespace std;

struct Segment {
    long long l, r, rate;
};

static constexpr Segment segments[] = {
    {0,      10,     10},
    {11,     230,    5},
    {231,    559,    8},
    {560,    1009,   2},
    {1010,   5000,   7},
    {5001,   10000,  8},
    {10001,  1000000000LL, 3}
};

int chargingTime(int S, int T) {
    long long charge = S;
    int time = 0;

    for (auto &seg : segments) {
        if (charge >= T) break;
        if (charge > seg.r || T <= seg.l) continue;
        long long boundary = min(seg.r + 1, (long long)T);
        long long need = boundary - charge;
        long long minutes = (need + seg.rate - 1) / seg.rate;
        time += minutes;
        charge += minutes * seg.rate;
    }

    return time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Q; 
    cin >> Q;
    while (Q--) {
        int S, T;
        cin >> S >> T;
        cout << chargingTime(S, T) <<endl;
    }
    return 0;
}
