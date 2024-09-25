class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        struct TrieNode {
            int count = 0;
            TrieNode* children[26] = {};
        };
        
        TrieNode* root = new TrieNode();
      
        auto insert = [&](const string& word) {
            TrieNode* node = root;
            for (char c : word) {
                if (!node->children[c - 'a'])
                    node->children[c - 'a'] = new TrieNode();
                node = node->children[c - 'a'];
                node->count++;
            }
        };
        
        auto getScore = [&](const string& word) {
            TrieNode* node = root;
            int score = 0;
            for (char c : word) {
                if (!node->children[c - 'a']) break;
                node = node->children[c - 'a'];
                score += node->count;
            }
            return score;
        };
        
  
        for (const string& word : words)
            insert(word);
        
                vector<int> result;
        for (const string& word : words)
            result.push_back(getScore(word));
        
        return result;
    }
};