class Solution {
public:
    int doOp(char op, int a, int b) {
        if (op == '+')
            return a + b;
        if (op == '-')
            return a - b;
        if (op == '*')
            return a * b;
        assert(false);
        return -1;
    }

    
        
        if (r - l == 1 && isdigit(s[r]))
            return {(s[l] - '0') * 10 + s[r] - '0'};

        vector<int> curr;
        for (int k = l + 1; k < r; k++) {
            if (!isdigit(s[k])) {
                vector<int> left = waysCompute(s, l, k - 1); 
                vector<int> right = waysCompute(s, k + 1, r);
                for (int val1 : left) {
                    for (int val2 : right) {
                        curr.push_back(doOp(s[k], val1, val2));
                    }
                }
            }
        }
        return curr;
    }

    vector<int> diffWaysToCompute(string &s) {
        return waysCompute(s, 0, s.size() - 1);
    }
};