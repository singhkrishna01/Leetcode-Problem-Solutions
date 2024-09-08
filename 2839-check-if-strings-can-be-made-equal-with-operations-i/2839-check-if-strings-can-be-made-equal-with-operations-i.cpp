class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if (s1.size() != s2.size()) {
        }
        
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[i]) {
            } else {
                if (s1[i+2] == s2[i]) {
                    swap(s1[i], s1[i+2]);
                    }
                }
            }
        
        
        return s1 == s2;
    }
};

