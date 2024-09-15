class Solution {
public:
    int findTheLongestSubstring(string s) {
        int longest_len=0;
        int n=s.size();
        unordered_map<int,int> mp;
        int mask=0;
        mp[0]=-1;

        for(int i=0;i<n;i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                mask^=(1<<(s[i]-'a'));
            }
            
            }  
        }
        return longest_len;
    }
};