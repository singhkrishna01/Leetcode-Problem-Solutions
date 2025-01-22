class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isWater[i][j] == 1){
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            
            for(const auto& [dx, dy]: dir) {
                int ni = i + dx, nj = j + dy;
                if(ni >= 0 && nj >= 0 && ni < n && nj < m && ans[ni][nj] == -1) {
                    ans[ni][nj] = ans[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }
        return ans;
    }
};