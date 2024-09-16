class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string words;
        while (ss >> words) {
            if (ans != "")
                ans = words + " " + ans;
            else
                ans = words + ans;
        }
        return ans;
    }
};