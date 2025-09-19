// User function Template for C++
class Solution {
  public:
    void topoSort(int node, vector<vector<pair<int, int>>>& adjList, vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        
        for(auto it : adjList[node]) {
            if(!vis[it.first]) {
                topoSort(it.first, adjList, vis, st);
            }
        }
        
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<int> dist(V, 1e9);
        vector<int> vis(V, 0);
        vector<vector<pair<int, int>>> adjList(V);
        
        for (int i = 0; i < E; ++i) {
            adjList[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
        }
        
        stack<int> st;
        
        for (int i = 0; i < V; ++i) {
            if(!vis[i]) {
                topoSort(i, adjList, vis, st);
            }
        }
        dist[0] = 0;
        
        while(!st.empty()) {
            int node = st.top(); st.pop();
            
            for(auto it : adjList[node]) {
                int v = it.first;
                int wt = it.second;
                dist[v] = min(dist[v], dist[node] + wt);
            }
        }
        
        for(int i = 0; i < V; ++i) {
            if (dist[i] == 1e9) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};