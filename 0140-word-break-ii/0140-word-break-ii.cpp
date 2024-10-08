class Solution {
private:
    void backtrack(string& s, int index, unordered_set<string>& set, string curr, vector<string>& res){
        if (index == s.length()) {res.push_back(curr); return;}
        string t = "";
        for (int i = index; i < s.size(); i++){
            t += s[i];
            if (set.find(t) != set.end()){
                backtrack(s, i+1, set, curr + t + (i < s.length()-1 ? " ":""), res);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
   