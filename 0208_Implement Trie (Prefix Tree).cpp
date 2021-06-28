class Trie {
    struct TrieNode{
        vector<TrieNode*> next;
        bool isEnd;
        TrieNode(bool isEnd = false):isEnd(isEnd){
            next.resize(26, nullptr);
        };
    };
    TrieNode* root;
    
    TrieNode* visit(string word){
        TrieNode* cur = root;
        int idx = 0;
        while (idx < word.length()){
            if (!cur->next[word[idx] - 'a']){
                return nullptr;
            }
            cur = cur->next[word[idx] - 'a'];
            idx++;
        }
        return cur;
    }
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        int idx = 0;
        while (idx < word.length()){
            if (!cur->next[word[idx] - 'a']){
                cur->next[word[idx] - 'a'] = new TrieNode();
            }
            cur = cur->next[word[idx] - 'a'];
            idx++;
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* end = visit(word);
        if (!end) return false;
        return end->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* end = visit(prefix);
        if (!end) return false;
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
