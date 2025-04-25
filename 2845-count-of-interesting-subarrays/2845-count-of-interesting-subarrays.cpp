long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
    int n = nums.size();
    vector<long long > ps(n + 1, 0);
    unordered_map<long long , long long > frq;

    ps[0] = 0;
    frq[0] = 1;
    long long  ans = 0;

    for (int i = 0; i < n; i++) {ps[i + 1] = (ps[i] + (nums[i] % modulo == k ? 1 : 0)) % modulo;
        long long  xp = (ps[i + 1] - k + modulo) % modulo;
            ans += frq[xp];
            frq[ps[i + 1]]++;
    }

    return ans;
};