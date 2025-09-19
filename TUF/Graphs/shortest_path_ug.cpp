class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int nodes = adj.size();
        vector<int> dist(nodes, -1);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        
        while(!q.empty()) {
            int currNode = q.front(); q.pop();
            for (auto it : adj[currNode]) {
                if(dist[it] == -1) {
                    dist[it] = dist[currNode] + 1;
                    q.push(it);
                }
            }
        }
        
        return dist;
    }
};