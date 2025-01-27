class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        vector <set <int>> adj(n);
        for(auto V: prerequisites){
            int x = V[0];
            int y = V[1];
            adj[x].insert(y);
        }

        vector <int> visited(n, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(adj[j].count(i)){
                    adj[j].insert(adj[i].begin(), adj[i].end());
                }
            }
        }

        int m = queries.size();
        vector <bool> ans(m, false);

        for(int i = 0; i < m; i++){
            int x = queries[i][0];
            int y = queries[i][1];

            if(adj[x].count(y)) ans[i] = true;
        }

        return ans;
    }
};