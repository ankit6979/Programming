class Solution {
    public:
        void bfs(string& dominoes, string& final_state, queue<int>& order, vector<int>& visited) {
            while(!order.empty()) {
                int current_domino = order.front();
                order.pop();
                if(final_state[current_domino] == 'L') {
                    if(current_domino - 1 >= 0) {
                        if(final_state[current_domino - 1] == '.') {
                            final_state[current_domino - 1] = 'L';
                            visited[current_domino - 1] = visited[current_domino] + 1;
                            order.push(current_domino - 1);
                        }
                        else if(visited[current_domino - 1] >= visited[current_domino] + 1 && final_state[current_domino - 1] == 'R') {
                            final_state[current_domino - 1] = '.';
                            visited[current_domino - 1] = visited[current_domino] + 1;
                        }
                    }
                }
                else if(final_state[current_domino] == 'R') {
                    if(current_domino + 1 < final_state.size()) {
                        if(final_state[current_domino + 1] == '.') {
                            final_state[current_domino + 1] = 'R';
                            visited[current_domino + 1] = visited[current_domino] + 1;
                            order.push(current_domino + 1);
                        }
                        else if(visited[current_domino + 1] >= visited[current_domino] + 1 && final_state[current_domino + 1] == 'L') {
                            final_state[current_domino + 1] = '.';
                            visited[current_domino + 1] = visited[current_domino] + 1;
                        }
                    }
                }
            }
        }
        string pushDominoes(string dominoes) {
            queue<int> order;
            string final_state = dominoes;
    
            vector<int> visited(dominoes.size() + 1, 0);
    
            for (int i = 0; i < dominoes.size(); ++i) {
                if(dominoes[i] == 'L' || dominoes[i] == 'R') {
                    order.push(i);
                }
            }
    
            bfs(dominoes, final_state, order, visited);
    
            return final_state;
        }
    };