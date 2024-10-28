class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
       
        unordered_set<int> st(nums.begin(), nums.end());
        int maxlength = 0;
        for (int num : nums) {
            long long current = num;
            int length = 0;
            while (st.find(current) != st.end()) {
                length++;
                if (current * current > 1e5) {
                    break;
                }
                current = current * current;
            }
            maxlength = max(maxlength, length);
        }

        return maxlength < 2 ? -1 : maxlength;
    }
};