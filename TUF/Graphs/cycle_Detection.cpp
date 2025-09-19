//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycleHelper(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = node;
        queue<int> q;
        q.push(node);
        
        while(!q.empty()) {
            int root = q.front();
            q.pop();
            
            for(int i = 0; i < adj[root].size(); ++i) {
                if(visited[adj[root][i]] == -1) {
                    q.push(adj[root][i]);
                    visited[adj[root][i]] = root;
                }
                else if(adj[root][i] != visited[root]) {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        int nodes = adj.size();
        vector<int> visited(nodes, -1);
        
        for (int i = 0; i < nodes; ++i) {
            if(visited[i] == -1) {
                bool is_cycle = isCycleHelper(i, adj, visited);
                if(is_cycle) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends