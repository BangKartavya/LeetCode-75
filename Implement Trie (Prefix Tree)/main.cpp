class TrieNode {
public:
    char val;
    bool isEnd;
    TrieNode* children[26];

    TrieNode(char val) {
        this->val = val;
        isEnd = false;
        for(int i = 0;i<26;i++) {
            children[i] = nullptr;
        }
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

        for(char& ch: word) {
            if(currNode->children[ch-'a'] == nullptr) {
                currNode->children[ch-'a'] = new TrieNode(ch);
            }

            currNode = currNode->children[ch-'a'];
        }

        currNode->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* currNode = root;

        for(char& ch: word) {
            if(currNode->children[ch-'a'] == nullptr) {
                return false;
            }
            currNode = currNode->children[ch-'a'];
        }

        return currNode->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* currNode = root;

        for(char& ch: prefix) {
            if(currNode->children[ch-'a'] == nullptr) {
                return false;
            }
            currNode = currNode->children[ch-'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */