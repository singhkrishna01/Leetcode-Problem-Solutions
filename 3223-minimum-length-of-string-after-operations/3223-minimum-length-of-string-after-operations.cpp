class Solution {
public:
    int minimumLength(string s) {
        int freq[26] = {0};  
        int n = s.length();
        
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        
        int removable = 0;
        for (int count : freq) {
            if (count > 2) {
                removable += count - (count % 2 == 0 ? 2 : 1);
            }
        }return n - removable;
    }
};