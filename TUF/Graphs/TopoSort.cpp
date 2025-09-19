class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> in_degree(numCourses, 0);
        vector<int> ans;
        queue<int> q;

        for(int i = 0; i < prerequisites.size(); ++i) {
            in_degree[prerequisites[i][0]] += 1;
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i = 0; i < numCourses; ++i) {
            if(in_degree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int curr_node = q.front(); q.pop();
            ans.push_back(curr_node);
            for(auto itr : graph[curr_node]) {
                in_degree[itr] -= 1;
                if(in_degree[itr] == 0) {
                    q.push(itr);
                }
            }
        }
        if(ans.size() == numCourses) {
            return ans;
        }
        return {};
    }
};