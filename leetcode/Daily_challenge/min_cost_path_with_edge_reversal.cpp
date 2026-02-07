class Solution {
public:
    int shortestDistance (int src, int tgt, int n, vector<vector<pair<int, int>>>& adjList) {
        const int INF = INT_MAX;
        vector<int> dist (n + 1, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [currDist, u] = pq.top(); pq.pop();

            if (currDist > dist[u]) continue;

            for (auto [v, wt] : adjList[u]) {
                if (dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        if (dist[tgt] == INF) {
            return -1;
        }
        return dist[tgt];
    }
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adjList (n + 1);

        for (int edge = 0; edge < edges.size(); ++edge) {
            adjList[edges[edge][0]].push_back(make_pair(edges[edge][1], edges[edge][2]));
            adjList[edges[edge][1]].push_back(make_pair(edges[edge][0], 2 * edges[edge][2]));
        }

        return shortestDistance(0, n - 1, n, adjList);
    }
};