class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int closest_node = -1, curr_node, dist, max_distance = -1, min_distance = INT_MAX;
        vector<int> visited1(edges.size(), -1);
        vector<int> visited (edges.size(), -1);

        curr_node = node1;
        dist = 0;
        do {
            visited1[curr_node] = dist;
            int next_node = edges[curr_node];
            curr_node = next_node;
            dist += 1;
        } while(curr_node != -1 && visited1[curr_node] == -1);

        curr_node = node2;
        dist = 0;
        
        do {
            if(visited1[curr_node] != -1) {
                max_distance = max(visited1[curr_node], dist);
                if(max_distance < min_distance) {
                    min_distance = max_distance;
                    closest_node = curr_node;
                }
                if(max_distance == min_distance) {
                    closest_node = min(curr_node, closest_node);
                }
            }
            visited[curr_node] = 1;
            curr_node = edges[curr_node];
            dist += 1;
        } while(curr_node != -1 && visited[curr_node] == -1);

        return closest_node;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();