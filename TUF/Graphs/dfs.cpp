class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& ans) {
        visited[node] = 1;
        ans.push_back(node);
        for (int i = 0; i < adj[node].size(); ++i) {
            if(visited[adj[node][i]] == 0) {
                dfs(adj[node][i], adj, visited, ans);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        vector<int> ans;
        vector<int> visited(adj.size(), 0);
        
        int start = 0;

        dfs(start, adj, visited, ans);
        
        return ans;
    }
};