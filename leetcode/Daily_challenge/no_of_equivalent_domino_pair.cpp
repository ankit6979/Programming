class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            map<pair<int, int>, int> dominoes_freq;
            int equivalent_pair = 0;
    
            for(int domino = 0; domino < dominoes.size(); ++domino) {
                dominoes_freq[{dominoes[domino][0], dominoes[domino][1]}] += 1;
            }
    
            for(int domino = 0; domino < dominoes.size(); ++domino) {
                int curr_domino_freq = 0, rotated_domino_freq = 0;
                if(dominoes_freq.find({dominoes[domino][0], dominoes[domino][1]}) != dominoes_freq.end()) {
                    curr_domino_freq =  dominoes_freq[{dominoes[domino][0], dominoes[domino][1]}];
                    dominoes_freq[{dominoes[domino][0], dominoes[domino][1]}] = 0;
                }
                if(dominoes_freq.find({dominoes[domino][1], dominoes[domino][0]}) != dominoes_freq.end()) {
                    rotated_domino_freq =  dominoes_freq[{dominoes[domino][1], dominoes[domino][0]}];
                    dominoes_freq[{dominoes[domino][1], dominoes[domino][0]}] = 0;
                }
                int total_domino_freq = curr_domino_freq + rotated_domino_freq;
    
                if(total_domino_freq >= 2) {
                    equivalent_pair += (((total_domino_freq) * (total_domino_freq - 1)) / 2);
                }
    
            }
    
            return equivalent_pair;
        }
    };