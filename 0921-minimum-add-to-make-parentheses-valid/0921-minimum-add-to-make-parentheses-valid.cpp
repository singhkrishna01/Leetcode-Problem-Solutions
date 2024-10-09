class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;

        for(auto &c: s) {
            if(!stk.empty() && c == ')' && stk.top() == '(') {
                stk.pop();
                continue;
            }
            stk.push(c);
        }

        return stk.size();
    }
};