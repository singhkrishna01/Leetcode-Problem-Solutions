class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> res(2 * n - 1, 0);
        vector<bool> used(n + 1, false);

        function<bool(int)> backtrack = [&](int idx) {
            if (idx == res.size()) return true;
            if (res[idx] != 0) return backtrack(idx + 1);
            for (int num = n; num >= 1; --num) {
                if (used[num]) continue;
                if (num == 1) {
                    res[idx] = 1;
                    used[1] = true;
                    if (backtrack(idx + 1)) return true;
                    res[idx] = 0;
                    used[1] = false;
                } else if (idx + num < res.size() && res[idx + num] == 0) {
                    res[idx] = res[idx + num] = num;
                    if (backtrack(idx + 1)) return true;
                    res[idx] = res[idx + num] = 0;
                    used[num] = false;
                }
            }
            return false;
        };

        backtrack(0);
        return res;
    }
};