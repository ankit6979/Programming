class TrieNode {
    public:
        vector<TrieNode*> link;
        bool wordEnd;

        TrieNode() {
            link = vector<TrieNode*>(26, nullptr);
            wordEnd = false;
        }
        
        bool containsKey(char ch) {
            return link[ch - 'a'] != NULL;
        }

        void setNode(char ch) {
            link[ch - 'a'] = new TrieNode();
        }

        TrieNode* getNext(char ch) {
            return link[ch - 'a'];
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

        void insert(string word) {
            TrieNode* node = root;
            for (char ch : word) {
                if(!node->containsKey(ch)) {
                    node->setNode(ch);
                }
                node = node->getNext(ch);
            }
            node->setWordEnd();
        }

        bool search(string word) {
            TrieNode* node = root;
            for(char ch : word) {
                if(!node->containsKey(ch)) {
                    return false;
                }
                node = node->getNext(ch);
            }
            return node->getWordEnd();
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

                for(int i = 25; i >= 0; --i) {
                    if(curr_node->containsKey('a' + i)) {
                        char ch = 'a' + i;
                        TrieNode* next = curr_node->getNext(ch);
                        s.push({next, path + "/" + ch});
                    }
                }
            }
        }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;

        Trie* trie = new Trie();

        for (string files : folder) {
            string word = "";
            for(auto file : files) {
                if(file != '/') {
                    word += file;
                }
            }
            trie->insert(word);
        }
        
        trie->dfs(ans);

        return ans;
    }
};