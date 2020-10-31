int TrieSize = 0;
struct TrieNode {
    bool EndWord;
    TrieNode *Child[26];
};
TrieNode* root;
TrieNode* AllocNode() {
    TrieNode * r = new (TrieNode);
    r -> EndWord = false;
    for (int i=0; i<26; i++)
        r -> Child[i] = nullptr;
    return r;
}
void InsertNode(string s) {
    TrieNode* foo = root;
    for (int i=0; i<s.size(); i++) {
        if (foo -> Child[s[i] - 'a'] == nullptr) {
            foo -> Child[s[i] - 'a'] = AllocNode();
        }
        foo = foo -> Child[s[i] - 'a'];
    }
    if (foo -> EndWord == false) {
        foo -> EndWord = true;
        TrieSize++;
    }
}
