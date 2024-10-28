class Solution {
public:
    
    void dfs(int src, int par, vector<pair<int, int>> adj[], int &cnt)
    {
        for(auto it : adj[src])
        {
            int child = it.first;
            if(child != par)
            {
                cnt += it.second;
                dfs(child, src, adj, cnt);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int, int>> adj[n];
        for(auto it : connections)
        {
            adj[it[0]].push_back({it[1], 1});
            adj[it[1]].push_back({it[0], 0});
        }

        int cnt = 0;
        dfs(0, -1, adj, cnt);
        return cnt;
    }
};