 class Solution {
public:
long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
    unordered_map<int, long long> freq;
    freq[0] = 1;
    long long prefix = 0, res = 0;

    for (int num : nums) {
        if (num % modulo == k)
            prefix++;
        int modVal = (int)(prefix % modulo);
        int need = (modVal - k + modulo) % modulo;
        res += freq[need];
        freq[modVal]++;
    }

    return res;
}
};