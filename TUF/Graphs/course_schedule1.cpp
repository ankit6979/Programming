class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int topoSort = 0;
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);
        queue<int> q;

        for (int i = 0; i < prerequisites.size(); ++i) {
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]] += 1;
        }

        for (int i = 0; i < numCourses; ++i) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            topoSort += 1;
            int node = q.front(); q.pop();
            for(auto it : adjList[node]) {
                inDegree[it] -= 1;
                if(inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return topoSort == numCourses ? 1 : 0;
    }
};