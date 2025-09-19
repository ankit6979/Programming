class TrieNode {
    public:
        map<string, TrieNode*> link;
        bool wordEnd;

        TrieNode() {
            // link = vector<TrieNode*>(26, nullptr);
            wordEnd = false;
        }
        
        bool containsKey(string filename) {
            return link[filename] != NULL;
        }

        void setNode(string filename) {
            link[filename] = new TrieNode();
        }

        TrieNode* getNext(string filename) {
            return link[filename];
        }

        void setWordEnd() {
            wordEnd = true;
        }

        void unSetWordEnd() {
            wordEnd = false;
        }

        bool getWordEnd() {
            return wordEnd;
        }
};

class Trie {
    private:
        TrieNode* root;
    
    public:
        Trie() {
            root = new TrieNode();
        }

        void insert(vector<string>& words) {
            TrieNode* node = root;
            for (auto word : words) {
                if(!node->containsKey(word)) {
                    node->setNode(word);
                }
                node = node->getNext(word);
            }
            node->setWordEnd();
        }

        void dfs(vector<string>& ans) {
            struct NodeWithPath {
                TrieNode* node;
                string path;
            };

            stack<NodeWithPath> s;
            s.push({root, ""});

            while(!s.empty()) {
                auto [curr_node, path] = s.top();
                s.pop();

                if (curr_node->getWordEnd()) {
                    ans.push_back(path);
                    continue;
                }

                for(const auto& [key, value] : curr_node->link) {
                    if(value != nullptr) {
                        s.push({value, path + "/" + key});
                    }
                }
            }
        }
};

class Solution {
public:
    vector<string> split(const string& path) {
        vector<string> parts;
        string curr = "";
        for (char c : path) {
            if (c == '/') {
                if (!curr.empty()) {
                    parts.push_back(curr);
                    curr.clear();
                }
            } else {
                curr += c;
            }
        }
        if (!curr.empty()) parts.push_back(curr);
        return parts;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        vector<string> words;

        Trie* trie = new Trie();

        for (const string& files : folder) {
            vector<string> parts = split(files);
            trie->insert(parts);
        }
        
        trie->dfs(ans);

        return ans;
    }
};