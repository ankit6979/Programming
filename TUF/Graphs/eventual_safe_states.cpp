class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<int> inDegree(nodes, 0);
        vector<vector<int>> adjList(nodes);
        vector<int> ans;
        queue<int> q;

        for (int i = 0; i < nodes; ++i) {
            inDegree[i] = graph[i].size();
            if(inDegree[i] == 0) {
                q.push(i);
            }
            for (auto it : graph[i]) {
                adjList[it].push_back(i);
            }
        }

        while(!q.empty()) {
            int node = q.front(); q.pop();
            ans.push_back(node);

            for (auto it : adjList[node]) {
                inDegree[it] -= 1;
                if(inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};