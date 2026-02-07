#define ll long long
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const ll INF = INT_MAX;
        vector<vector<ll>> dist(26, vector<ll> (26, INF));
        
        for (int i =0; i < 26; ++i) {
            dist[i][i] = 0;
        }

        for (int idx = 0; idx < original.size(); ++idx) {
            int u = original[idx] - 'a';
            int v = changed[idx] - 'a';
            dist[u][v] = min (dist[u][v], (ll)cost[idx]);
        }
        
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        ll ans = 0;
        for (int i = 0; i < source.size(); i++) {
            if (source[i] != target[i]) {
                int u = source[i] - 'a';
                int v = target[i] - 'a';
                if (dist[u][v] == INF) return -1;
                ans += dist[u][v];
            }
        }
        return ans;
    }
};