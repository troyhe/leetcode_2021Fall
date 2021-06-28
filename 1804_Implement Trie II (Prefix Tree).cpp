class Trie {
    struct TrieNode{
        vector<TrieNode*> next;
        int countEnd;
        int countStartWith;
        TrieNode():countEnd(0), countStartWith(0){
            next.resize(26, nullptr);
        };
    };
    TrieNode* root;
    
    TrieNode* visit(string word){
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); i++){
            if (!cur->next[word[i] - 'a']){
                return nullptr;
            }
            cur = cur->next[word[i] - 'a'];
        }
        return cur;
    }
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); i++){
            if (!cur->next[word[i] - 'a']){
                cur->next[word[i] - 'a'] = new TrieNode();
            }
            cur = cur->next[word[i] - 'a'];
            cur->countStartWith += 1;
        }
        cur->countEnd += 1;
    }
    
    int countWordsEqualTo(string word) {
        TrieNode* end = visit(word);
        if (!end) return 0;
        return end->countEnd;
    }
    
    int countWordsStartingWith(string prefix) {
        TrieNode* end = visit(prefix);
        if (!end) return 0;
        return end->countStartWith;
    }
    
    void erase(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); i++){
            cur = cur->next[word[i] - 'a'];
            cur->countStartWith -= 1;
        }
        cur->countEnd -= 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
