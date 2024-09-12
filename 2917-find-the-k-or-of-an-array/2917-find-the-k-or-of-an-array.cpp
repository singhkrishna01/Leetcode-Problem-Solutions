class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        vector<int> bit_count(32, 0);
        int result = 0;
        for (const int& num : nums) {
            for (int i = 0; i < 32; i++) {
                if (((1 << i) & num) == 0) continue;
                if ((++bit_count[i]) == k) result |= (1 << i);
            }
        }
        return result;
    }
};