class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> roads(n);
        vector<int> d(n, 0);
        for (int i = 1; i < n; i++) 
            d[i] = i;
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0], fin = queries[i][1];
            roads[start].push_back(fin);
            for (int j = start; j < n; j++) {
                for (auto dest : roads[j]) {
                    d[dest] = min(d[dest], d[j] + 1);
                }
                for (int k = fin + 1; k < n; k++) {
                    d[k] = min(d[k], d[k-1] + 1);
                }
            }
            ans.push_back(d[n-1]);
        }

        return ans;
    }
};