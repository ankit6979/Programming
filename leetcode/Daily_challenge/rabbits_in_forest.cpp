class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            int totalAnswers = answers.size(), minRabbits = 0;
            unordered_map<int, int> colors;
    
            for (int i = 0; i < totalAnswers; ++i) {
                if(colors.find(answers[i] + 1) != colors.end()) {
                    if(colors[answers[i] + 1] > 0) {
                        colors[answers[i] + 1] -= 1;
                    }
                    else {
                        minRabbits += (answers[i] + 1);
                        colors[answers[i] + 1] = answers[i];
                    }
                }
                else {
                    colors[answers[i] + 1] = answers[i];
                }
            }
    
            unordered_map<int, int> :: iterator it = colors.begin();
    
            while(it != colors.end()) {
                minRabbits += it->first;
                it++;
            }
    
            return minRabbits;
        }
    };
    auto init = []() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        return 'c';
    }();