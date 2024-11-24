class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int mn = INT_MAX;
        long long sum = 0;
        int count = 0;
        for (auto p : matrix) {
            for (auto q : p) {
                int val = q;
                if (val < 0)
                    val = -1 * val;
                sum += val;
                if (val < mn)
                    mn = val;
                if (q < 0)
                    count++;
            }
        }
        cout << sum << endl;
        if (count % 2 == 0)
            return sum;
        return sum - 2 * mn;
    }
};