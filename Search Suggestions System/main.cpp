class TrieNode {
    public:
        char val;
        bool isEnd;
        TrieNode* children[26] = {nullptr};

        TrieNode(char val) {
            this->val = val;
            isEnd = false;
        }
};

class Trie {
    private:
        TrieNode* root;

    public:
        Trie() {
            root = new TrieNode(-1);
        }

        void insert(string word) {
            TrieNode* currNode = root;

            for(char& ch : word) {
                if(currNode->children[ch - 'a'] == nullptr) {
                    currNode->children[ch - 'a'] = new TrieNode(ch);
                }

                currNode = currNode->children[ch - 'a'];
            }

            currNode->isEnd = true;
        }

        void findWords(TrieNode* currNode, string currWord, vector<string>& res) {
            if(currNode->isEnd) {
                res.push_back(currWord);
            }

            for(int i = 0; i < 26; i++) {
                if(res.size() == 3) return;
                if(currNode->children[i] != nullptr) {
                    currWord.push_back(i + 'a');
                    findWords(currNode->children[i], currWord, res);
                    currWord.pop_back();
                }
            }
        }

        vector<string> results(string searchWord) {
            TrieNode* currNode = root;

            for(char& ch : searchWord) {
                if(currNode->children[ch - 'a'] == nullptr) return {};

                currNode = currNode->children[ch - 'a'];
            }

            vector<string> res;
            findWords(currNode, searchWord, res);
            return res;
        }
};

class Solution {
    public:
        vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
            Trie* prefixTree = new Trie();

            for(string& str : products) {
                prefixTree->insert(str);
            }
            vector<vector<string>> result;

            for(int i = 1; i <= searchWord.size(); i++) {
                result.push_back(prefixTree->results(searchWord.substr(0, i)));
            }
            return result;
        }
};