class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        map<int, int> mp;
        
        int res = 0;
        for (auto it: mp)
        {
            if (it.second != 1)
                res ^= it.first;
        }
        
        return res;
    }
};