class Solution {
public:

    vector<vector<string>> ans;
    vector<string> candidate;
    bool is_palindrome(string s, int l, int r)
    {
    void solve(string s, int i, int previous)
    {
            if(is_palindrome(s, previous, i))
            {
                candidate.push_back(s.substr(previous, i-previous+1));
                solve(s, i+1, i+1);
                candidate.pop_back();
            }
            solve(s, i+1, previous);
        }
    }

    vector<vector<string>> partition(string s)
    {
        solve(s, 0, 0);
        return ans;
    }
};